// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: proto/config_runner/config_runner.proto

#include "proto/config_runner/config_runner.pb.h"
#include "proto/config_runner/config_runner.grpc.pb.h"

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

static const char* ConfigRunner_method_names[] = {
  "/ConfigRunner/ConfigRun",
  "/ConfigRunner/Shutdown",
};

std::unique_ptr< ConfigRunner::Stub> ConfigRunner::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ConfigRunner::Stub> stub(new ConfigRunner::Stub(channel));
  return stub;
}

ConfigRunner::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_ConfigRun_(ConfigRunner_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Shutdown_(ConfigRunner_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ConfigRunner::Stub::ConfigRun(::grpc::ClientContext* context, const ::ConfigRunRequest& request, ::ConfigRunResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_ConfigRun_, context, request, response);
}

void ConfigRunner::Stub::experimental_async::ConfigRun(::grpc::ClientContext* context, const ::ConfigRunRequest* request, ::ConfigRunResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_ConfigRun_, context, request, response, std::move(f));
}

void ConfigRunner::Stub::experimental_async::ConfigRun(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ConfigRunResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_ConfigRun_, context, request, response, std::move(f));
}

void ConfigRunner::Stub::experimental_async::ConfigRun(::grpc::ClientContext* context, const ::ConfigRunRequest* request, ::ConfigRunResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_ConfigRun_, context, request, response, reactor);
}

void ConfigRunner::Stub::experimental_async::ConfigRun(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ConfigRunResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_ConfigRun_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::ConfigRunResponse>* ConfigRunner::Stub::AsyncConfigRunRaw(::grpc::ClientContext* context, const ::ConfigRunRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::ConfigRunResponse>::Create(channel_.get(), cq, rpcmethod_ConfigRun_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ConfigRunResponse>* ConfigRunner::Stub::PrepareAsyncConfigRunRaw(::grpc::ClientContext* context, const ::ConfigRunRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::ConfigRunResponse>::Create(channel_.get(), cq, rpcmethod_ConfigRun_, context, request, false);
}

::grpc::Status ConfigRunner::Stub::Shutdown(::grpc::ClientContext* context, const ::ShutdownRequest& request, ::ShutdownResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Shutdown_, context, request, response);
}

void ConfigRunner::Stub::experimental_async::Shutdown(::grpc::ClientContext* context, const ::ShutdownRequest* request, ::ShutdownResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Shutdown_, context, request, response, std::move(f));
}

void ConfigRunner::Stub::experimental_async::Shutdown(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ShutdownResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Shutdown_, context, request, response, std::move(f));
}

void ConfigRunner::Stub::experimental_async::Shutdown(::grpc::ClientContext* context, const ::ShutdownRequest* request, ::ShutdownResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Shutdown_, context, request, response, reactor);
}

void ConfigRunner::Stub::experimental_async::Shutdown(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ShutdownResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Shutdown_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::ShutdownResponse>* ConfigRunner::Stub::AsyncShutdownRaw(::grpc::ClientContext* context, const ::ShutdownRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::ShutdownResponse>::Create(channel_.get(), cq, rpcmethod_Shutdown_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ShutdownResponse>* ConfigRunner::Stub::PrepareAsyncShutdownRaw(::grpc::ClientContext* context, const ::ShutdownRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::ShutdownResponse>::Create(channel_.get(), cq, rpcmethod_Shutdown_, context, request, false);
}

ConfigRunner::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConfigRunner_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ConfigRunner::Service, ::ConfigRunRequest, ::ConfigRunResponse>(
          [](ConfigRunner::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::ConfigRunRequest* req,
             ::ConfigRunResponse* resp) {
               return service->ConfigRun(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConfigRunner_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ConfigRunner::Service, ::ShutdownRequest, ::ShutdownResponse>(
          [](ConfigRunner::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::ShutdownRequest* req,
             ::ShutdownResponse* resp) {
               return service->Shutdown(ctx, req, resp);
             }, this)));
}

ConfigRunner::Service::~Service() {
}

::grpc::Status ConfigRunner::Service::ConfigRun(::grpc::ServerContext* context, const ::ConfigRunRequest* request, ::ConfigRunResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ConfigRunner::Service::Shutdown(::grpc::ServerContext* context, const ::ShutdownRequest* request, ::ShutdownResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


