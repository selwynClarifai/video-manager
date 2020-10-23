// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: proto/inference_coordinator/inference_coordinator.proto

#include "proto/inference_coordinator/inference_coordinator.pb.h"
#include "proto/inference_coordinator/inference_coordinator.grpc.pb.h"

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

static const char* InferenceCoordinator_method_names[] = {
  "/InferenceCoordinator/DeploySpire",
  "/InferenceCoordinator/DeleteSpire",
  "/InferenceCoordinator/GetSpireDeployStatus",
  "/InferenceCoordinator/ListSpires",
};

std::unique_ptr< InferenceCoordinator::Stub> InferenceCoordinator::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< InferenceCoordinator::Stub> stub(new InferenceCoordinator::Stub(channel));
  return stub;
}

InferenceCoordinator::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_DeploySpire_(InferenceCoordinator_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_DeleteSpire_(InferenceCoordinator_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetSpireDeployStatus_(InferenceCoordinator_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_ListSpires_(InferenceCoordinator_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status InferenceCoordinator::Stub::DeploySpire(::grpc::ClientContext* context, const ::DeploySpireRequest& request, ::DeploySpireResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_DeploySpire_, context, request, response);
}

void InferenceCoordinator::Stub::experimental_async::DeploySpire(::grpc::ClientContext* context, const ::DeploySpireRequest* request, ::DeploySpireResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_DeploySpire_, context, request, response, std::move(f));
}

void InferenceCoordinator::Stub::experimental_async::DeploySpire(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::DeploySpireResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_DeploySpire_, context, request, response, std::move(f));
}

void InferenceCoordinator::Stub::experimental_async::DeploySpire(::grpc::ClientContext* context, const ::DeploySpireRequest* request, ::DeploySpireResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_DeploySpire_, context, request, response, reactor);
}

void InferenceCoordinator::Stub::experimental_async::DeploySpire(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::DeploySpireResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_DeploySpire_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::DeploySpireResponse>* InferenceCoordinator::Stub::AsyncDeploySpireRaw(::grpc::ClientContext* context, const ::DeploySpireRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::DeploySpireResponse>::Create(channel_.get(), cq, rpcmethod_DeploySpire_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::DeploySpireResponse>* InferenceCoordinator::Stub::PrepareAsyncDeploySpireRaw(::grpc::ClientContext* context, const ::DeploySpireRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::DeploySpireResponse>::Create(channel_.get(), cq, rpcmethod_DeploySpire_, context, request, false);
}

::grpc::Status InferenceCoordinator::Stub::DeleteSpire(::grpc::ClientContext* context, const ::DeleteSpireRequest& request, ::DeleteSpireResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_DeleteSpire_, context, request, response);
}

void InferenceCoordinator::Stub::experimental_async::DeleteSpire(::grpc::ClientContext* context, const ::DeleteSpireRequest* request, ::DeleteSpireResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_DeleteSpire_, context, request, response, std::move(f));
}

void InferenceCoordinator::Stub::experimental_async::DeleteSpire(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::DeleteSpireResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_DeleteSpire_, context, request, response, std::move(f));
}

void InferenceCoordinator::Stub::experimental_async::DeleteSpire(::grpc::ClientContext* context, const ::DeleteSpireRequest* request, ::DeleteSpireResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_DeleteSpire_, context, request, response, reactor);
}

void InferenceCoordinator::Stub::experimental_async::DeleteSpire(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::DeleteSpireResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_DeleteSpire_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::DeleteSpireResponse>* InferenceCoordinator::Stub::AsyncDeleteSpireRaw(::grpc::ClientContext* context, const ::DeleteSpireRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::DeleteSpireResponse>::Create(channel_.get(), cq, rpcmethod_DeleteSpire_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::DeleteSpireResponse>* InferenceCoordinator::Stub::PrepareAsyncDeleteSpireRaw(::grpc::ClientContext* context, const ::DeleteSpireRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::DeleteSpireResponse>::Create(channel_.get(), cq, rpcmethod_DeleteSpire_, context, request, false);
}

::grpc::Status InferenceCoordinator::Stub::GetSpireDeployStatus(::grpc::ClientContext* context, const ::GetSpireDeployStatusRequest& request, ::GetSpireDeployStatusResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetSpireDeployStatus_, context, request, response);
}

void InferenceCoordinator::Stub::experimental_async::GetSpireDeployStatus(::grpc::ClientContext* context, const ::GetSpireDeployStatusRequest* request, ::GetSpireDeployStatusResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetSpireDeployStatus_, context, request, response, std::move(f));
}

void InferenceCoordinator::Stub::experimental_async::GetSpireDeployStatus(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::GetSpireDeployStatusResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetSpireDeployStatus_, context, request, response, std::move(f));
}

void InferenceCoordinator::Stub::experimental_async::GetSpireDeployStatus(::grpc::ClientContext* context, const ::GetSpireDeployStatusRequest* request, ::GetSpireDeployStatusResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetSpireDeployStatus_, context, request, response, reactor);
}

void InferenceCoordinator::Stub::experimental_async::GetSpireDeployStatus(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::GetSpireDeployStatusResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetSpireDeployStatus_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::GetSpireDeployStatusResponse>* InferenceCoordinator::Stub::AsyncGetSpireDeployStatusRaw(::grpc::ClientContext* context, const ::GetSpireDeployStatusRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::GetSpireDeployStatusResponse>::Create(channel_.get(), cq, rpcmethod_GetSpireDeployStatus_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::GetSpireDeployStatusResponse>* InferenceCoordinator::Stub::PrepareAsyncGetSpireDeployStatusRaw(::grpc::ClientContext* context, const ::GetSpireDeployStatusRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::GetSpireDeployStatusResponse>::Create(channel_.get(), cq, rpcmethod_GetSpireDeployStatus_, context, request, false);
}

::grpc::Status InferenceCoordinator::Stub::ListSpires(::grpc::ClientContext* context, const ::ListSpiresRequest& request, ::ListSpiresResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_ListSpires_, context, request, response);
}

void InferenceCoordinator::Stub::experimental_async::ListSpires(::grpc::ClientContext* context, const ::ListSpiresRequest* request, ::ListSpiresResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_ListSpires_, context, request, response, std::move(f));
}

void InferenceCoordinator::Stub::experimental_async::ListSpires(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ListSpiresResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_ListSpires_, context, request, response, std::move(f));
}

void InferenceCoordinator::Stub::experimental_async::ListSpires(::grpc::ClientContext* context, const ::ListSpiresRequest* request, ::ListSpiresResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_ListSpires_, context, request, response, reactor);
}

void InferenceCoordinator::Stub::experimental_async::ListSpires(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ListSpiresResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_ListSpires_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::ListSpiresResponse>* InferenceCoordinator::Stub::AsyncListSpiresRaw(::grpc::ClientContext* context, const ::ListSpiresRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::ListSpiresResponse>::Create(channel_.get(), cq, rpcmethod_ListSpires_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ListSpiresResponse>* InferenceCoordinator::Stub::PrepareAsyncListSpiresRaw(::grpc::ClientContext* context, const ::ListSpiresRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::ListSpiresResponse>::Create(channel_.get(), cq, rpcmethod_ListSpires_, context, request, false);
}

InferenceCoordinator::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      InferenceCoordinator_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< InferenceCoordinator::Service, ::DeploySpireRequest, ::DeploySpireResponse>(
          [](InferenceCoordinator::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::DeploySpireRequest* req,
             ::DeploySpireResponse* resp) {
               return service->DeploySpire(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      InferenceCoordinator_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< InferenceCoordinator::Service, ::DeleteSpireRequest, ::DeleteSpireResponse>(
          [](InferenceCoordinator::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::DeleteSpireRequest* req,
             ::DeleteSpireResponse* resp) {
               return service->DeleteSpire(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      InferenceCoordinator_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< InferenceCoordinator::Service, ::GetSpireDeployStatusRequest, ::GetSpireDeployStatusResponse>(
          [](InferenceCoordinator::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::GetSpireDeployStatusRequest* req,
             ::GetSpireDeployStatusResponse* resp) {
               return service->GetSpireDeployStatus(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      InferenceCoordinator_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< InferenceCoordinator::Service, ::ListSpiresRequest, ::ListSpiresResponse>(
          [](InferenceCoordinator::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::ListSpiresRequest* req,
             ::ListSpiresResponse* resp) {
               return service->ListSpires(ctx, req, resp);
             }, this)));
}

InferenceCoordinator::Service::~Service() {
}

::grpc::Status InferenceCoordinator::Service::DeploySpire(::grpc::ServerContext* context, const ::DeploySpireRequest* request, ::DeploySpireResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status InferenceCoordinator::Service::DeleteSpire(::grpc::ServerContext* context, const ::DeleteSpireRequest* request, ::DeleteSpireResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status InferenceCoordinator::Service::GetSpireDeployStatus(::grpc::ServerContext* context, const ::GetSpireDeployStatusRequest* request, ::GetSpireDeployStatusResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status InferenceCoordinator::Service::ListSpires(::grpc::ServerContext* context, const ::ListSpiresRequest* request, ::ListSpiresResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


