# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

from proto.clarifai.sdk_billing import resources_pb2 as proto_dot_clarifai_dot_sdk__billing_dot_resources__pb2
from proto.clarifai.sdk_billing import service_pb2 as proto_dot_clarifai_dot_sdk__billing_dot_service__pb2


class SDKBillingServiceStub(object):
  # missing associated documentation comment in .proto file
  pass

  def __init__(self, channel):
    """Constructor.

    Args:
      channel: A grpc.Channel.
    """
    self.GetHealthz = channel.unary_unary(
        '/clarifai.sdk_billing.SDKBillingService/GetHealthz',
        request_serializer=proto_dot_clarifai_dot_sdk__billing_dot_service__pb2.GetHealthzRequest.SerializeToString,
        response_deserializer=proto_dot_clarifai_dot_sdk__billing_dot_service__pb2.GetHealthzResponse.FromString,
        )
    self.PostSDKBilling = channel.unary_unary(
        '/clarifai.sdk_billing.SDKBillingService/PostSDKBilling',
        request_serializer=proto_dot_clarifai_dot_sdk__billing_dot_resources__pb2.SDKBilling.SerializeToString,
        response_deserializer=proto_dot_clarifai_dot_sdk__billing_dot_service__pb2.SDKBillingResponse.FromString,
        )


class SDKBillingServiceServicer(object):
  # missing associated documentation comment in .proto file
  pass

  def GetHealthz(self, request, context):
    """Health Check
    """
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def PostSDKBilling(self, request, context):
    """Add a new sdk_billing entry into our database
    note(lowjiansheng): not following convention for request formats as this proto definition is being used in many parts of Mobile SDK
    """
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')


def add_SDKBillingServiceServicer_to_server(servicer, server):
  rpc_method_handlers = {
      'GetHealthz': grpc.unary_unary_rpc_method_handler(
          servicer.GetHealthz,
          request_deserializer=proto_dot_clarifai_dot_sdk__billing_dot_service__pb2.GetHealthzRequest.FromString,
          response_serializer=proto_dot_clarifai_dot_sdk__billing_dot_service__pb2.GetHealthzResponse.SerializeToString,
      ),
      'PostSDKBilling': grpc.unary_unary_rpc_method_handler(
          servicer.PostSDKBilling,
          request_deserializer=proto_dot_clarifai_dot_sdk__billing_dot_resources__pb2.SDKBilling.FromString,
          response_serializer=proto_dot_clarifai_dot_sdk__billing_dot_service__pb2.SDKBillingResponse.SerializeToString,
      ),
  }
  generic_handler = grpc.method_handlers_generic_handler(
      'clarifai.sdk_billing.SDKBillingService', rpc_method_handlers)
  server.add_generic_rpc_handlers((generic_handler,))