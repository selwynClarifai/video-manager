from __future__ import absolute_import, division, print_function
from future import standard_library
from future.moves.urllib.parse import quote
from past.builtins import unicode

import json
import os
import re
from builtins import map, object, range

import requests
from google.api.http_pb2 import HttpRule
#pylint: disable=no-name-in-module
#pylint: disable=import-error
from google.protobuf.json_format import MessageToDict, Parse, ParseDict

import proto.clarifai.api.status.status_code_pb2 as status_code
from proto.clarifai.api.service_pb2 import _V2

standard_library.install_aliases()

_ = Parse
_ = ParseDict

CLIENT_VERSION = '2.0.32'
OS_VER = os.sys.platform
PYTHON_VERSION = '.'.join(map(str, [os.sys.version_info.major, os.sys.version_info.minor, \
                                    os.sys.version_info.micro]))


class ResponseParseException(Exception):
  pass


class APIException(Exception):

  def __init__(self, message, response):
    self.response = response
    super(APIException, self).__init__(message)


class GRPCJSONChannel(object):
  """ This mimics the behaviour of a grpc channel object but allows transport over https with
  json request and response bodies.

  Currently there is only support for unary_unary requests. If you have any other type of grpc
  request this channel will nicely fail when trying to use within a grpc stub.

  Example:
    Assuming your top level endpoints are called V2 and in a proto/clarifai/api/endpoint.proto file,
    then you build those in python and can import the spec to use in GRPCJSONChannel as follows:

    from proto.clarifai.api.service_pb2_grpc import V2Stub
    from proto.clarifai.api.service_pb2 import _V2
    channel = GRPCJSONChannel(key="api key", service_descriptor=_V2)
    stub = V2Stub(channel)

    # Then you can use the stub to call just like grpc directly!!!
    result = stub.PostInputs(PostInputsRequest(inputs=[Input(data=Data(image=Image(url="http://...")))]))
  """

  def __init__(self,
               key,
               base_url="https://api.clarifai.com",
               service_descriptor=_V2,
               raise_for_status=False,
               req_id_prefix='python-client'):
    """
    Args:
      key: a string api key to use in the {"Authorization": "Key %s" % key} headers to send in each
    request.
      base_url: if you want to point at a different url than the default.
      service_description: This is a ServiceDescriptor object found in the compiled grpc-gateway
        .proto results. For example if your proto defining the endpoints is in service.proto then look
        in service_pb2.py file for ServiceDescriptor and use that.
      req_id_prefix: This is so to help recognize the request in the logs. This needs to be set for the
        testing env, for easier tracing.
    """
    self.base_url = base_url
    self.key = key
    self.name_to_method = {}
    self.raise_for_status = raise_for_status
    self.req_id_prefix = req_id_prefix

    for m in service_descriptor.methods:
      # This gets the google.api.http object from the .proto file that looks like this:
      # option (google.api.http) = {
      #   delete: "/v2/users/{user_app_id.user_id}/apps/{user_app_id.app_id}/models/{model_id}"
      #   additional_bindings {
      #     delete: "/v2/models/{model_id}"
      #   }
      # Then we check if there are additional_bindings and use that if so (because we've had the
      # convention of having the default urls in there and the not yet used urls at the top level.
      http_rule = None
      for field in m.GetOptions().ListFields():
        if isinstance(field[1], HttpRule):
          http_rule = field[1]
      if http_rule is None:
        raise Exception("Method %s is missing the HttpRule option, please add it." % (m.name))
      if len(http_rule.additional_bindings) > 0:
        http_rule = http_rule.additional_bindings[0]

      # Get the url template and the method to use for http.
      if http_rule.HasField('get'):
        method = 'GET'
        url_template = base_url + http_rule.get
      elif http_rule.HasField('post'):
        method = 'POST'
        url_template = base_url + http_rule.post
      elif http_rule.HasField('patch'):
        method = 'PATCH'
        url_template = base_url + http_rule.patch
      elif http_rule.HasField('put'):
        method = 'PUT'
        url_template = base_url + http_rule.put
      elif http_rule.HasField('delete'):
        method = 'DELETE'
        url_template = base_url + http_rule.delete
      else:
        raise Exception("Failed to parse the grpc-gateway service spec.")

      self.name_to_method['/' +
                          service_descriptor.full_name + '/' + m.name] = (url_template, method,
                                                                          m.input_type)

  def unary_unary(self, name, request_serializer, response_deserializer):
    """ Method to create the callable JSONUnaryUnary. """
    url_template, method, request_message_descriptor = self.name_to_method[name]
    return JSONUnaryUnary(self.key, url_template, method, request_message_descriptor,
                          request_serializer, response_deserializer, self.req_id_prefix,
                          self.raise_for_status)


class JSONUnaryUnary(object):
  """ This mimics the unary_unary calls and is actually the thing doing the http requests.
  """

  def __init__(self,
               key,
               url_template,
               method,
               request_message_descriptor,
               request_serializer,
               response_deserializer,
               req_id_prefix,
               raise_for_status=False):
    """
    Args:
      key: a string api key to use in the {"Authorization": "Key %s" % key} headers to send in each
    request.
      url_template: the url template for this method.
      method: the HTTP method to use for this request.
      input_type: this is a MessageDescriptor for the input type.
      request_serializer: the method to use to serialize the request proto
      response_deserializer: the response proto deserializer which will be used to convert the http
        response will be parsed into this.

    Returns:
      response: a proto object of class response_deserializer filled in with the response.
    """
    self.key = key
    self.url_template = url_template
    self.method = method
    self.request_message_descriptor = request_message_descriptor
    self.request_serializer = request_serializer
    self.response_deserializer = response_deserializer
    self.req_id_prefix = req_id_prefix
    self.raise_for_status = raise_for_status
    self.headers = self._construct_headers()
    self._url_regex = re.compile(r'\{{1}(.*?)\}{1}')

  def _construct_headers(self):
    headers = {
        'Content-Type': 'application/json',
        'X-Clarifai-Client': 'python:%s' % CLIENT_VERSION,
        'Python-Client': '%s:%s' % (OS_VER, PYTHON_VERSION),
        'X-Clarifai-Request-Id-Prefix': self.req_id_prefix,
        'Authorization': 'Key %s' % self.key,
    }
    return headers

  def _url_params(self, request_dict):
    """ This converts fills in the url template for this request with actual url safe params from
    the request body.
    Args:
      request_dict: a dictionary form of the request from json_format.MessageToDict(request,
        preserving_proto_field_name=True) so that we can recursively lookup url params.
    Returns:
      url: the url string to use in requests.
    """
    url = self.url_template
    for substitution in re.findall(self._url_regex, self.url_template):
      value = request_dict
      # recurse through the object dict and use get() which will fail if any url param is not set.
      for field in substitution.split('.'):
        value = value.get(field)
        if value is None:
          raise Exception(
              "You must set the following fields in your request proto: %s" % substitution)
      # prevent banned character as path variables hitting grpc gateway
      value = url_encode(value)
      # finally replace in the url the result of the recursive getting.
      url = url.replace('{' + substitution + '}', value)
    return url

  def __call__(self, request, metadata=None):
    """ This is where the actually calls come through when the stub is called such as
    stub.PostInputs(). They get passed to this method which actually makes the request.

    Args:
      request: the proto object for the request. It must be the proper type for the request or the
        server will complain. Note: this doesn't type check the incoming request in the client but
        does make sure it can serialize before sending to the server atleast.
      metadata: not used currently, just added to match grpc.

    Returns:
      response: the proto object that this method returns.
    """

    # There is no __self__ attribute on the request_serializer unfortunately.
    expected_object_name = self.request_message_descriptor.name
    if type(request).__name__ != expected_object_name:
      raise Exception("The input request must be of type: %s from %s" %
                      (expected_object_name, self.request_message_descriptor.file.name))

    params = MessageToDict(
        request, preserving_proto_field_name=True, including_default_value_fields=True)

    # Convert the url template to a proper url.
    url = self._url_params(params)
    headers = dict(self.headers)

    if self.method == 'GET':
      res = requests.get(url, params=params, headers=headers)
    elif self.method == "POST":
      res = requests.post(url, data=json.dumps(params), headers=headers)
    elif self.method == "DELETE":
      res = requests.delete(url, data=json.dumps(params), headers=headers)
    elif self.method == "PATCH":
      res = requests.patch(url, data=json.dumps(params), headers=headers)
    elif self.method == "PUT":
      res = requests.put(url, data=json.dumps(params), headers=headers)
    else:
      raise Exception("Unsupported request type: '%s'" % self.method)

    # Get the actual message object to construct
    result = self.response_deserializer.__self__()
    try:
      result = Parse(res.content, result)
    except:
      raise ResponseParseException('Error parsing json response from result: %s', res.content)

    if result.status.code != status_code.SUCCESS and self.raise_for_status:
      raise APIException('Request failed with status %r' % result.status, result)
    return result


def url_encode(dict_value):
  if isinstance(dict_value, unicode) or isinstance(dict_value, str):
    return quote(dict_value.encode('utf8'), safe='')
  elif isinstance(dict_value, dict):
    for k, v in list(dict_value.items()):
      dict_value[k] = url_encode(v)
  elif isinstance(dict_value, list):
    for i in range(len(dict_value)):
      dict_value[i] = url_encode(dict_value[i])
  return dict_value
