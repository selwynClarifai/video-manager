# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

from proto.lopq import lopq_service_pb2 as proto_dot_lopq_dot_lopq__service__pb2


class LOPQServiceStub(object):
    """Interface exported by the server.
    """

    def __init__(self, channel):
        """Constructor.

        Args:
            channel: A grpc.Channel.
        """
        self.LOPQPredict = channel.unary_unary(
                '/LOPQService/LOPQPredict',
                request_serializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQPredictRequest.SerializeToString,
                response_deserializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQPredictResponse.FromString,
                )
        self.LOPQSearch = channel.unary_unary(
                '/LOPQService/LOPQSearch',
                request_serializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchRequest.SerializeToString,
                response_deserializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchResponse.FromString,
                )
        self.LOPQAttributeSearch = channel.unary_unary(
                '/LOPQService/LOPQAttributeSearch',
                request_serializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQAttributeSearchRequest.SerializeToString,
                response_deserializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchResponse.FromString,
                )
        self.LOPQSearchForCodes = channel.unary_unary(
                '/LOPQService/LOPQSearchForCodes',
                request_serializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchForCodesRequest.SerializeToString,
                response_deserializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchForCodesResponse.FromString,
                )
        self.LOPQBruteForceSearch = channel.unary_unary(
                '/LOPQService/LOPQBruteForceSearch',
                request_serializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQBruteForceSearchRequest.SerializeToString,
                response_deserializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQBruteForceSearchResponse.FromString,
                )
        self.LOPQTrain = channel.unary_unary(
                '/LOPQService/LOPQTrain',
                request_serializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQTrainRequest.SerializeToString,
                response_deserializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQTrainResponse.FromString,
                )
        self.LOPQTrainAndEval = channel.unary_unary(
                '/LOPQService/LOPQTrainAndEval',
                request_serializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQTrainAndEvalRequest.SerializeToString,
                response_deserializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQTrainAndEvalResponse.FromString,
                )


class LOPQServiceServicer(object):
    """Interface exported by the server.
    """

    def LOPQPredict(self, request, context):
        """Predicts the LOPQ codes for given embeddings for a LOPQ model
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def LOPQSearch(self, request, context):
        """Searches for embeddings given an optional SQL template to only consider a subset of assets for a LOPQ model
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def LOPQAttributeSearch(self, request, context):
        """Searches for embeddings and attributes given a SQL template and custom models to weight results
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def LOPQSearchForCodes(self, request, context):
        """Searches for embeddings given a LOPQ model returning LOPQ coarse keys and distances only
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def LOPQBruteForceSearch(self, request, context):
        """Brute force search for nearest neighbors of query embeddings.
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def LOPQTrain(self, request, context):
        """LOPQTrain by iterating over database and then save model to s3.
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def LOPQTrainAndEval(self, request, context):
        """Evaluates a LOPQ model by comparing to brute force for a set of sample query embeddings.
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_LOPQServiceServicer_to_server(servicer, server):
    rpc_method_handlers = {
            'LOPQPredict': grpc.unary_unary_rpc_method_handler(
                    servicer.LOPQPredict,
                    request_deserializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQPredictRequest.FromString,
                    response_serializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQPredictResponse.SerializeToString,
            ),
            'LOPQSearch': grpc.unary_unary_rpc_method_handler(
                    servicer.LOPQSearch,
                    request_deserializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchRequest.FromString,
                    response_serializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchResponse.SerializeToString,
            ),
            'LOPQAttributeSearch': grpc.unary_unary_rpc_method_handler(
                    servicer.LOPQAttributeSearch,
                    request_deserializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQAttributeSearchRequest.FromString,
                    response_serializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchResponse.SerializeToString,
            ),
            'LOPQSearchForCodes': grpc.unary_unary_rpc_method_handler(
                    servicer.LOPQSearchForCodes,
                    request_deserializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchForCodesRequest.FromString,
                    response_serializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchForCodesResponse.SerializeToString,
            ),
            'LOPQBruteForceSearch': grpc.unary_unary_rpc_method_handler(
                    servicer.LOPQBruteForceSearch,
                    request_deserializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQBruteForceSearchRequest.FromString,
                    response_serializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQBruteForceSearchResponse.SerializeToString,
            ),
            'LOPQTrain': grpc.unary_unary_rpc_method_handler(
                    servicer.LOPQTrain,
                    request_deserializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQTrainRequest.FromString,
                    response_serializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQTrainResponse.SerializeToString,
            ),
            'LOPQTrainAndEval': grpc.unary_unary_rpc_method_handler(
                    servicer.LOPQTrainAndEval,
                    request_deserializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQTrainAndEvalRequest.FromString,
                    response_serializer=proto_dot_lopq_dot_lopq__service__pb2.LOPQTrainAndEvalResponse.SerializeToString,
            ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
            'LOPQService', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))


 # This class is part of an EXPERIMENTAL API.
class LOPQService(object):
    """Interface exported by the server.
    """

    @staticmethod
    def LOPQPredict(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/LOPQService/LOPQPredict',
            proto_dot_lopq_dot_lopq__service__pb2.LOPQPredictRequest.SerializeToString,
            proto_dot_lopq_dot_lopq__service__pb2.LOPQPredictResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def LOPQSearch(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/LOPQService/LOPQSearch',
            proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchRequest.SerializeToString,
            proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def LOPQAttributeSearch(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/LOPQService/LOPQAttributeSearch',
            proto_dot_lopq_dot_lopq__service__pb2.LOPQAttributeSearchRequest.SerializeToString,
            proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def LOPQSearchForCodes(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/LOPQService/LOPQSearchForCodes',
            proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchForCodesRequest.SerializeToString,
            proto_dot_lopq_dot_lopq__service__pb2.LOPQSearchForCodesResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def LOPQBruteForceSearch(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/LOPQService/LOPQBruteForceSearch',
            proto_dot_lopq_dot_lopq__service__pb2.LOPQBruteForceSearchRequest.SerializeToString,
            proto_dot_lopq_dot_lopq__service__pb2.LOPQBruteForceSearchResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def LOPQTrain(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/LOPQService/LOPQTrain',
            proto_dot_lopq_dot_lopq__service__pb2.LOPQTrainRequest.SerializeToString,
            proto_dot_lopq_dot_lopq__service__pb2.LOPQTrainResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def LOPQTrainAndEval(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/LOPQService/LOPQTrainAndEval',
            proto_dot_lopq_dot_lopq__service__pb2.LOPQTrainAndEvalRequest.SerializeToString,
            proto_dot_lopq_dot_lopq__service__pb2.LOPQTrainAndEvalResponse.FromString,
            options, channel_credentials,
            call_credentials, compression, wait_for_ready, timeout, metadata)
