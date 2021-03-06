# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

from proto.blur import blur_extent_pb2 as proto_dot_blur_dot_blur__extent__pb2


class BlurDetectionServiceStub(object):
    """Missing associated documentation comment in .proto file"""

    def __init__(self, channel):
        """Constructor.

        Args:
            channel: A grpc.Channel.
        """
        self.BlurDetect = channel.unary_unary(
                '/BlurDetectionService/BlurDetect',
                request_serializer=proto_dot_blur_dot_blur__extent__pb2.BlurDetectRequest.SerializeToString,
                response_deserializer=proto_dot_blur_dot_blur__extent__pb2.BlurDetectResponse.FromString,
                )


class BlurDetectionServiceServicer(object):
    """Missing associated documentation comment in .proto file"""

    def BlurDetect(self, request, context):
        """Missing associated documentation comment in .proto file"""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_BlurDetectionServiceServicer_to_server(servicer, server):
    rpc_method_handlers = {
            'BlurDetect': grpc.unary_unary_rpc_method_handler(
                    servicer.BlurDetect,
                    request_deserializer=proto_dot_blur_dot_blur__extent__pb2.BlurDetectRequest.FromString,
                    response_serializer=proto_dot_blur_dot_blur__extent__pb2.BlurDetectResponse.SerializeToString,
            ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
            'BlurDetectionService', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))


 # This class is part of an EXPERIMENTAL API.
class BlurDetectionService(object):
    """Missing associated documentation comment in .proto file"""

    @staticmethod
    def BlurDetect(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/BlurDetectionService/BlurDetect',
            proto_dot_blur_dot_blur__extent__pb2.BlurDetectRequest.SerializeToString,
            proto_dot_blur_dot_blur__extent__pb2.BlurDetectResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)
