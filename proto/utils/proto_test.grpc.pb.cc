// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: proto/utils/proto_test.proto

#include "proto/utils/proto_test.pb.h"
#include "proto/utils/proto_test.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>

static const char* ProtoTestService_method_names[] = {
  "/ProtoTestService/ProtoTestPredict",
};

std::unique_ptr< ProtoTestService::Stub> ProtoTestService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ProtoTestService::Stub> stub(new ProtoTestService::Stub(channel));
  return stub;
}

ProtoTestService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_ProtoTestPredict_(ProtoTestService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ProtoTestService::Stub::ProtoTestPredict(::grpc::ClientContext* context, const ::ProtoTestRequest& request, ::ProtoTestResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_ProtoTestPredict_, context, request, response);
}

void ProtoTestService::Stub::experimental_async::ProtoTestPredict(::grpc::ClientContext* context, const ::ProtoTestRequest* request, ::ProtoTestResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_ProtoTestPredict_, context, request, response, std::move(f));
}

void ProtoTestService::Stub::experimental_async::ProtoTestPredict(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ProtoTestResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_ProtoTestPredict_, context, request, response, std::move(f));
}

void ProtoTestService::Stub::experimental_async::ProtoTestPredict(::grpc::ClientContext* context, const ::ProtoTestRequest* request, ::ProtoTestResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_ProtoTestPredict_, context, request, response, reactor);
}

void ProtoTestService::Stub::experimental_async::ProtoTestPredict(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ProtoTestResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_ProtoTestPredict_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::ProtoTestResponse>* ProtoTestService::Stub::AsyncProtoTestPredictRaw(::grpc::ClientContext* context, const ::ProtoTestRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::ProtoTestResponse>::Create(channel_.get(), cq, rpcmethod_ProtoTestPredict_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ProtoTestResponse>* ProtoTestService::Stub::PrepareAsyncProtoTestPredictRaw(::grpc::ClientContext* context, const ::ProtoTestRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::ProtoTestResponse>::Create(channel_.get(), cq, rpcmethod_ProtoTestPredict_, context, request, false);
}

ProtoTestService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ProtoTestService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ProtoTestService::Service, ::ProtoTestRequest, ::ProtoTestResponse>(
          [](ProtoTestService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::ProtoTestRequest* req,
             ::ProtoTestResponse* resp) {
               return service->ProtoTestPredict(ctx, req, resp);
             }, this)));
}

ProtoTestService::Service::~Service() {
}

::grpc::Status ProtoTestService::Service::ProtoTestPredict(::grpc::ServerContext* context, const ::ProtoTestRequest* request, ::ProtoTestResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


