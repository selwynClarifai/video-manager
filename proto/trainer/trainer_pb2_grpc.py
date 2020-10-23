# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

from proto.trainer import trainer_pb2 as proto_dot_trainer_dot_trainer__pb2


class TrainingCoordinatorStub(object):
    """Interface exported by the server.
    """

    def __init__(self, channel):
        """Constructor.

        Args:
            channel: A grpc.Channel.
        """
        self.Train = channel.unary_unary(
                '/TrainingCoordinator/Train',
                request_serializer=proto_dot_trainer_dot_trainer__pb2.TrainRequest.SerializeToString,
                response_deserializer=proto_dot_trainer_dot_trainer__pb2.TrainResponse.FromString,
                )
        self.GetStatus = channel.unary_unary(
                '/TrainingCoordinator/GetStatus',
                request_serializer=proto_dot_trainer_dot_trainer__pb2.GetStatusRequest.SerializeToString,
                response_deserializer=proto_dot_trainer_dot_trainer__pb2.GetStatusResponse.FromString,
                )
        self.GetEvaluations = channel.unary_unary(
                '/TrainingCoordinator/GetEvaluations',
                request_serializer=proto_dot_trainer_dot_trainer__pb2.GetEvaluationsRequest.SerializeToString,
                response_deserializer=proto_dot_trainer_dot_trainer__pb2.GetEvaluationsResponse.FromString,
                )
        self.ListTemplates = channel.unary_unary(
                '/TrainingCoordinator/ListTemplates',
                request_serializer=proto_dot_trainer_dot_trainer__pb2.ListTemplatesRequest.SerializeToString,
                response_deserializer=proto_dot_trainer_dot_trainer__pb2.ListTemplatesResponse.FromString,
                )
        self.GetSpireConfig = channel.unary_unary(
                '/TrainingCoordinator/GetSpireConfig',
                request_serializer=proto_dot_trainer_dot_trainer__pb2.GetSpireConfigRequest.SerializeToString,
                response_deserializer=proto_dot_trainer_dot_trainer__pb2.GetSpireConfigResponse.FromString,
                )
        self.EidCleanUp = channel.unary_unary(
                '/TrainingCoordinator/EidCleanUp',
                request_serializer=proto_dot_trainer_dot_trainer__pb2.EidCleanUpRequest.SerializeToString,
                response_deserializer=proto_dot_trainer_dot_trainer__pb2.EidCleanUpResponse.FromString,
                )


class TrainingCoordinatorServicer(object):
    """Interface exported by the server.
    """

    def Train(self, request, context):
        """Train a model
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def GetStatus(self, request, context):
        """Get status of training job
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def GetEvaluations(self, request, context):
        """Get evaluation metrics for the training job
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def ListTemplates(self, request, context):
        """List training templates and doc strings
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def GetSpireConfig(self, request, context):
        """Get spire name
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def EidCleanUp(self, request, context):
        """Cleanup files no longer needed
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_TrainingCoordinatorServicer_to_server(servicer, server):
    rpc_method_handlers = {
            'Train': grpc.unary_unary_rpc_method_handler(
                    servicer.Train,
                    request_deserializer=proto_dot_trainer_dot_trainer__pb2.TrainRequest.FromString,
                    response_serializer=proto_dot_trainer_dot_trainer__pb2.TrainResponse.SerializeToString,
            ),
            'GetStatus': grpc.unary_unary_rpc_method_handler(
                    servicer.GetStatus,
                    request_deserializer=proto_dot_trainer_dot_trainer__pb2.GetStatusRequest.FromString,
                    response_serializer=proto_dot_trainer_dot_trainer__pb2.GetStatusResponse.SerializeToString,
            ),
            'GetEvaluations': grpc.unary_unary_rpc_method_handler(
                    servicer.GetEvaluations,
                    request_deserializer=proto_dot_trainer_dot_trainer__pb2.GetEvaluationsRequest.FromString,
                    response_serializer=proto_dot_trainer_dot_trainer__pb2.GetEvaluationsResponse.SerializeToString,
            ),
            'ListTemplates': grpc.unary_unary_rpc_method_handler(
                    servicer.ListTemplates,
                    request_deserializer=proto_dot_trainer_dot_trainer__pb2.ListTemplatesRequest.FromString,
                    response_serializer=proto_dot_trainer_dot_trainer__pb2.ListTemplatesResponse.SerializeToString,
            ),
            'GetSpireConfig': grpc.unary_unary_rpc_method_handler(
                    servicer.GetSpireConfig,
                    request_deserializer=proto_dot_trainer_dot_trainer__pb2.GetSpireConfigRequest.FromString,
                    response_serializer=proto_dot_trainer_dot_trainer__pb2.GetSpireConfigResponse.SerializeToString,
            ),
            'EidCleanUp': grpc.unary_unary_rpc_method_handler(
                    servicer.EidCleanUp,
                    request_deserializer=proto_dot_trainer_dot_trainer__pb2.EidCleanUpRequest.FromString,
                    response_serializer=proto_dot_trainer_dot_trainer__pb2.EidCleanUpResponse.SerializeToString,
            ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
            'TrainingCoordinator', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))


 # This class is part of an EXPERIMENTAL API.
class TrainingCoordinator(object):
    """Interface exported by the server.
    """

    @staticmethod
    def Train(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/TrainingCoordinator/Train',
            proto_dot_trainer_dot_trainer__pb2.TrainRequest.SerializeToString,
            proto_dot_trainer_dot_trainer__pb2.TrainResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def GetStatus(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/TrainingCoordinator/GetStatus',
            proto_dot_trainer_dot_trainer__pb2.GetStatusRequest.SerializeToString,
            proto_dot_trainer_dot_trainer__pb2.GetStatusResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def GetEvaluations(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/TrainingCoordinator/GetEvaluations',
            proto_dot_trainer_dot_trainer__pb2.GetEvaluationsRequest.SerializeToString,
            proto_dot_trainer_dot_trainer__pb2.GetEvaluationsResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def ListTemplates(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/TrainingCoordinator/ListTemplates',
            proto_dot_trainer_dot_trainer__pb2.ListTemplatesRequest.SerializeToString,
            proto_dot_trainer_dot_trainer__pb2.ListTemplatesResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def GetSpireConfig(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/TrainingCoordinator/GetSpireConfig',
            proto_dot_trainer_dot_trainer__pb2.GetSpireConfigRequest.SerializeToString,
            proto_dot_trainer_dot_trainer__pb2.GetSpireConfigResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def EidCleanUp(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/TrainingCoordinator/EidCleanUp',
            proto_dot_trainer_dot_trainer__pb2.EidCleanUpRequest.SerializeToString,
            proto_dot_trainer_dot_trainer__pb2.EidCleanUpResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)