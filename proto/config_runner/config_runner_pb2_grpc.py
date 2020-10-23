# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

from proto.config_runner import config_runner_pb2 as proto_dot_config__runner_dot_config__runner__pb2


class ConfigRunnerStub(object):
    """Missing associated documentation comment in .proto file"""

    def __init__(self, channel):
        """Constructor.

        Args:
            channel: A grpc.Channel.
        """
        self.ConfigRun = channel.unary_unary(
                '/ConfigRunner/ConfigRun',
                request_serializer=proto_dot_config__runner_dot_config__runner__pb2.ConfigRunRequest.SerializeToString,
                response_deserializer=proto_dot_config__runner_dot_config__runner__pb2.ConfigRunResponse.FromString,
                )
        self.Shutdown = channel.unary_unary(
                '/ConfigRunner/Shutdown',
                request_serializer=proto_dot_config__runner_dot_config__runner__pb2.ShutdownRequest.SerializeToString,
                response_deserializer=proto_dot_config__runner_dot_config__runner__pb2.ShutdownResponse.FromString,
                )


class ConfigRunnerServicer(object):
    """Missing associated documentation comment in .proto file"""

    def ConfigRun(self, request, context):
        """Missing associated documentation comment in .proto file"""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def Shutdown(self, request, context):
        """Missing associated documentation comment in .proto file"""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_ConfigRunnerServicer_to_server(servicer, server):
    rpc_method_handlers = {
            'ConfigRun': grpc.unary_unary_rpc_method_handler(
                    servicer.ConfigRun,
                    request_deserializer=proto_dot_config__runner_dot_config__runner__pb2.ConfigRunRequest.FromString,
                    response_serializer=proto_dot_config__runner_dot_config__runner__pb2.ConfigRunResponse.SerializeToString,
            ),
            'Shutdown': grpc.unary_unary_rpc_method_handler(
                    servicer.Shutdown,
                    request_deserializer=proto_dot_config__runner_dot_config__runner__pb2.ShutdownRequest.FromString,
                    response_serializer=proto_dot_config__runner_dot_config__runner__pb2.ShutdownResponse.SerializeToString,
            ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
            'ConfigRunner', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))


 # This class is part of an EXPERIMENTAL API.
class ConfigRunner(object):
    """Missing associated documentation comment in .proto file"""

    @staticmethod
    def ConfigRun(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/ConfigRunner/ConfigRun',
            proto_dot_config__runner_dot_config__runner__pb2.ConfigRunRequest.SerializeToString,
            proto_dot_config__runner_dot_config__runner__pb2.ConfigRunResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def Shutdown(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/ConfigRunner/Shutdown',
            proto_dot_config__runner_dot_config__runner__pb2.ShutdownRequest.SerializeToString,
            proto_dot_config__runner_dot_config__runner__pb2.ShutdownResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)