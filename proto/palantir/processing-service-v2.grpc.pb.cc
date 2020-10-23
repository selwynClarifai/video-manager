// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: proto/palantir/processing-service-v2.proto

#include "proto/palantir/processing-service-v2.pb.h"
#include "proto/palantir/processing-service-v2.grpc.pb.h"

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
namespace aip {
namespace processor {
namespace v2 {

static const char* ProcessingService_method_names[] = {
  "/aip.processor.v2.ProcessingService/GeoRegister",
  "/aip.processor.v2.ProcessingService/Infer",
  "/aip.processor.v2.ProcessingService/Track",
};

std::unique_ptr< ProcessingService::Stub> ProcessingService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ProcessingService::Stub> stub(new ProcessingService::Stub(channel));
  return stub;
}

ProcessingService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_GeoRegister_(ProcessingService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Infer_(ProcessingService_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Track_(ProcessingService_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ProcessingService::Stub::GeoRegister(::grpc::ClientContext* context, const ::aip::processor::v2::GeoRegistrationRequest& request, ::aip::processor::v2::GeoRegistrationResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GeoRegister_, context, request, response);
}

void ProcessingService::Stub::experimental_async::GeoRegister(::grpc::ClientContext* context, const ::aip::processor::v2::GeoRegistrationRequest* request, ::aip::processor::v2::GeoRegistrationResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GeoRegister_, context, request, response, std::move(f));
}

void ProcessingService::Stub::experimental_async::GeoRegister(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::aip::processor::v2::GeoRegistrationResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GeoRegister_, context, request, response, std::move(f));
}

void ProcessingService::Stub::experimental_async::GeoRegister(::grpc::ClientContext* context, const ::aip::processor::v2::GeoRegistrationRequest* request, ::aip::processor::v2::GeoRegistrationResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GeoRegister_, context, request, response, reactor);
}

void ProcessingService::Stub::experimental_async::GeoRegister(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::aip::processor::v2::GeoRegistrationResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GeoRegister_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::aip::processor::v2::GeoRegistrationResponse>* ProcessingService::Stub::AsyncGeoRegisterRaw(::grpc::ClientContext* context, const ::aip::processor::v2::GeoRegistrationRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::aip::processor::v2::GeoRegistrationResponse>::Create(channel_.get(), cq, rpcmethod_GeoRegister_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::aip::processor::v2::GeoRegistrationResponse>* ProcessingService::Stub::PrepareAsyncGeoRegisterRaw(::grpc::ClientContext* context, const ::aip::processor::v2::GeoRegistrationRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::aip::processor::v2::GeoRegistrationResponse>::Create(channel_.get(), cq, rpcmethod_GeoRegister_, context, request, false);
}

::grpc::Status ProcessingService::Stub::Infer(::grpc::ClientContext* context, const ::aip::processor::v2::InferenceRequest& request, ::aip::processor::v2::InferenceResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Infer_, context, request, response);
}

void ProcessingService::Stub::experimental_async::Infer(::grpc::ClientContext* context, const ::aip::processor::v2::InferenceRequest* request, ::aip::processor::v2::InferenceResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Infer_, context, request, response, std::move(f));
}

void ProcessingService::Stub::experimental_async::Infer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::aip::processor::v2::InferenceResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Infer_, context, request, response, std::move(f));
}

void ProcessingService::Stub::experimental_async::Infer(::grpc::ClientContext* context, const ::aip::processor::v2::InferenceRequest* request, ::aip::processor::v2::InferenceResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Infer_, context, request, response, reactor);
}

void ProcessingService::Stub::experimental_async::Infer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::aip::processor::v2::InferenceResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Infer_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::aip::processor::v2::InferenceResponse>* ProcessingService::Stub::AsyncInferRaw(::grpc::ClientContext* context, const ::aip::processor::v2::InferenceRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::aip::processor::v2::InferenceResponse>::Create(channel_.get(), cq, rpcmethod_Infer_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::aip::processor::v2::InferenceResponse>* ProcessingService::Stub::PrepareAsyncInferRaw(::grpc::ClientContext* context, const ::aip::processor::v2::InferenceRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::aip::processor::v2::InferenceResponse>::Create(channel_.get(), cq, rpcmethod_Infer_, context, request, false);
}

::grpc::Status ProcessingService::Stub::Track(::grpc::ClientContext* context, const ::aip::processor::v2::TrackRequest& request, ::aip::processor::v2::InferenceResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Track_, context, request, response);
}

void ProcessingService::Stub::experimental_async::Track(::grpc::ClientContext* context, const ::aip::processor::v2::TrackRequest* request, ::aip::processor::v2::InferenceResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Track_, context, request, response, std::move(f));
}

void ProcessingService::Stub::experimental_async::Track(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::aip::processor::v2::InferenceResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Track_, context, request, response, std::move(f));
}

void ProcessingService::Stub::experimental_async::Track(::grpc::ClientContext* context, const ::aip::processor::v2::TrackRequest* request, ::aip::processor::v2::InferenceResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Track_, context, request, response, reactor);
}

void ProcessingService::Stub::experimental_async::Track(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::aip::processor::v2::InferenceResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Track_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::aip::processor::v2::InferenceResponse>* ProcessingService::Stub::AsyncTrackRaw(::grpc::ClientContext* context, const ::aip::processor::v2::TrackRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::aip::processor::v2::InferenceResponse>::Create(channel_.get(), cq, rpcmethod_Track_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::aip::processor::v2::InferenceResponse>* ProcessingService::Stub::PrepareAsyncTrackRaw(::grpc::ClientContext* context, const ::aip::processor::v2::TrackRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::aip::processor::v2::InferenceResponse>::Create(channel_.get(), cq, rpcmethod_Track_, context, request, false);
}

ProcessingService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ProcessingService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ProcessingService::Service, ::aip::processor::v2::GeoRegistrationRequest, ::aip::processor::v2::GeoRegistrationResponse>(
          [](ProcessingService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::aip::processor::v2::GeoRegistrationRequest* req,
             ::aip::processor::v2::GeoRegistrationResponse* resp) {
               return service->GeoRegister(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ProcessingService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ProcessingService::Service, ::aip::processor::v2::InferenceRequest, ::aip::processor::v2::InferenceResponse>(
          [](ProcessingService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::aip::processor::v2::InferenceRequest* req,
             ::aip::processor::v2::InferenceResponse* resp) {
               return service->Infer(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ProcessingService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ProcessingService::Service, ::aip::processor::v2::TrackRequest, ::aip::processor::v2::InferenceResponse>(
          [](ProcessingService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::aip::processor::v2::TrackRequest* req,
             ::aip::processor::v2::InferenceResponse* resp) {
               return service->Track(ctx, req, resp);
             }, this)));
}

ProcessingService::Service::~Service() {
}

::grpc::Status ProcessingService::Service::GeoRegister(::grpc::ServerContext* context, const ::aip::processor::v2::GeoRegistrationRequest* request, ::aip::processor::v2::GeoRegistrationResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ProcessingService::Service::Infer(::grpc::ServerContext* context, const ::aip::processor::v2::InferenceRequest* request, ::aip::processor::v2::InferenceResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ProcessingService::Service::Track(::grpc::ServerContext* context, const ::aip::processor::v2::TrackRequest* request, ::aip::processor::v2::InferenceResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace aip
}  // namespace processor
}  // namespace v2
