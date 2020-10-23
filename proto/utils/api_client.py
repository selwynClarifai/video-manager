from __future__ import absolute_import, division, print_function
from future import standard_library

import proto.utils.api_v2_resources
from proto.clarifai.api.service_pb2 import _V2
from proto.clarifai.api.service_pb2_grpc import V2Stub
from proto.utils.grpc_json_channel import GRPCJSONChannel

standard_library.install_aliases()

BASE_URLS = {
    'prod': 'https://api.clarifai.com',
    'staging': 'https://api-staging.clarifai.com',
}


class ApiV2(V2Stub):

  def __init__(self, access_key, base_url=BASE_URLS['prod']):
    channel = GRPCJSONChannel(
        key=access_key,
        base_url=base_url,
        service_descriptor=_V2,
    )
    V2Stub.__init__(self, channel)

  def resources(self):
    return proto.utils.api_v2_resources
