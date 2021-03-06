# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

from proto.color import color_pb2 as proto_dot_color_dot_color__pb2


class ColorServiceStub(object):
    """Missing associated documentation comment in .proto file"""

    def __init__(self, channel):
        """Constructor.

        Args:
            channel: A grpc.Channel.
        """
        self.ColorPredict = channel.unary_unary(
                '/ColorService/ColorPredict',
                request_serializer=proto_dot_color_dot_color__pb2.ColorPredictRequest.SerializeToString,
                response_deserializer=proto_dot_color_dot_color__pb2.ColorPredictResponse.FromString,
                )


class ColorServiceServicer(object):
    """Missing associated documentation comment in .proto file"""

    def ColorPredict(self, request, context):
        """Missing associated documentation comment in .proto file"""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_ColorServiceServicer_to_server(servicer, server):
    rpc_method_handlers = {
            'ColorPredict': grpc.unary_unary_rpc_method_handler(
                    servicer.ColorPredict,
                    request_deserializer=proto_dot_color_dot_color__pb2.ColorPredictRequest.FromString,
                    response_serializer=proto_dot_color_dot_color__pb2.ColorPredictResponse.SerializeToString,
            ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
            'ColorService', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))


 # This class is part of an EXPERIMENTAL API.
class ColorService(object):
    """Missing associated documentation comment in .proto file"""

    @staticmethod
    def ColorPredict(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/ColorService/ColorPredict',
            proto_dot_color_dot_color__pb2.ColorPredictRequest.SerializeToString,
            proto_dot_color_dot_color__pb2.ColorPredictResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)
