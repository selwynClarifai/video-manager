# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

from proto.utils import proto_test_pb2 as proto_dot_utils_dot_proto__test__pb2


class ProtoTestServiceStub(object):
    """Interface exported by the server.
    """

    def __init__(self, channel):
        """Constructor.

        Args:
            channel: A grpc.Channel.
        """
        self.ProtoTestPredict = channel.unary_unary(
                '/ProtoTestService/ProtoTestPredict',
                request_serializer=proto_dot_utils_dot_proto__test__pb2.ProtoTestRequest.SerializeToString,
                response_deserializer=proto_dot_utils_dot_proto__test__pb2.ProtoTestResponse.FromString,
                )


class ProtoTestServiceServicer(object):
    """Interface exported by the server.
    """

    def ProtoTestPredict(self, request, context):
        """Predict given a trained model and embeddings from some examples
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_ProtoTestServiceServicer_to_server(servicer, server):
    rpc_method_handlers = {
            'ProtoTestPredict': grpc.unary_unary_rpc_method_handler(
                    servicer.ProtoTestPredict,
                    request_deserializer=proto_dot_utils_dot_proto__test__pb2.ProtoTestRequest.FromString,
                    response_serializer=proto_dot_utils_dot_proto__test__pb2.ProtoTestResponse.SerializeToString,
            ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
            'ProtoTestService', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))


 # This class is part of an EXPERIMENTAL API.
class ProtoTestService(object):
    """Interface exported by the server.
    """

    @staticmethod
    def ProtoTestPredict(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/ProtoTestService/ProtoTestPredict',
            proto_dot_utils_dot_proto__test__pb2.ProtoTestRequest.SerializeToString,
            proto_dot_utils_dot_proto__test__pb2.ProtoTestResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)