// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: proto/media_processor/media_processor.proto

#include "proto/media_processor/media_processor.pb.h"
#include "proto/media_processor/media_processor.grpc.pb.h"

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

static const char* MediaProcessor_method_names[] = {
  "/MediaProcessor/MediaProcessorProcessImage",
  "/MediaProcessor/MediaProcessorProcessImageSync",
  "/MediaProcessor/MediaProcessorProcessVideo",
  "/MediaProcessor/MediaProcessorGetVideoThumbnail",
  "/MediaProcessor/MediaProcessorGetState",
};

std::unique_ptr< MediaProcessor::Stub> MediaProcessor::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< MediaProcessor::Stub> stub(new MediaProcessor::Stub(channel));
  return stub;
}

MediaProcessor::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_MediaProcessorProcessImage_(MediaProcessor_method_names[0], ::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_MediaProcessorProcessImageSync_(MediaProcessor_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_MediaProcessorProcessVideo_(MediaProcessor_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_MediaProcessorGetVideoThumbnail_(MediaProcessor_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_MediaProcessorGetState_(MediaProcessor_method_names[4], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::ClientReader< ::MediaProcessorProcessImageResponse>* MediaProcessor::Stub::MediaProcessorProcessImageRaw(::grpc::ClientContext* context, const ::MediaProcessorProcessImageRequest& request) {
  return ::grpc_impl::internal::ClientReaderFactory< ::MediaProcessorProcessImageResponse>::Create(channel_.get(), rpcmethod_MediaProcessorProcessImage_, context, request);
}

void MediaProcessor::Stub::experimental_async::MediaProcessorProcessImage(::grpc::ClientContext* context, ::MediaProcessorProcessImageRequest* request, ::grpc::experimental::ClientReadReactor< ::MediaProcessorProcessImageResponse>* reactor) {
  ::grpc_impl::internal::ClientCallbackReaderFactory< ::MediaProcessorProcessImageResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorProcessImage_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::MediaProcessorProcessImageResponse>* MediaProcessor::Stub::AsyncMediaProcessorProcessImageRaw(::grpc::ClientContext* context, const ::MediaProcessorProcessImageRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc_impl::internal::ClientAsyncReaderFactory< ::MediaProcessorProcessImageResponse>::Create(channel_.get(), cq, rpcmethod_MediaProcessorProcessImage_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::MediaProcessorProcessImageResponse>* MediaProcessor::Stub::PrepareAsyncMediaProcessorProcessImageRaw(::grpc::ClientContext* context, const ::MediaProcessorProcessImageRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncReaderFactory< ::MediaProcessorProcessImageResponse>::Create(channel_.get(), cq, rpcmethod_MediaProcessorProcessImage_, context, request, false, nullptr);
}

::grpc::Status MediaProcessor::Stub::MediaProcessorProcessImageSync(::grpc::ClientContext* context, const ::MediaProcessorProcessImageRequest& request, ::MediaProcessorProcessImageResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_MediaProcessorProcessImageSync_, context, request, response);
}

void MediaProcessor::Stub::experimental_async::MediaProcessorProcessImageSync(::grpc::ClientContext* context, const ::MediaProcessorProcessImageRequest* request, ::MediaProcessorProcessImageResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorProcessImageSync_, context, request, response, std::move(f));
}

void MediaProcessor::Stub::experimental_async::MediaProcessorProcessImageSync(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MediaProcessorProcessImageResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorProcessImageSync_, context, request, response, std::move(f));
}

void MediaProcessor::Stub::experimental_async::MediaProcessorProcessImageSync(::grpc::ClientContext* context, const ::MediaProcessorProcessImageRequest* request, ::MediaProcessorProcessImageResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorProcessImageSync_, context, request, response, reactor);
}

void MediaProcessor::Stub::experimental_async::MediaProcessorProcessImageSync(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MediaProcessorProcessImageResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorProcessImageSync_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MediaProcessorProcessImageResponse>* MediaProcessor::Stub::AsyncMediaProcessorProcessImageSyncRaw(::grpc::ClientContext* context, const ::MediaProcessorProcessImageRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MediaProcessorProcessImageResponse>::Create(channel_.get(), cq, rpcmethod_MediaProcessorProcessImageSync_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::MediaProcessorProcessImageResponse>* MediaProcessor::Stub::PrepareAsyncMediaProcessorProcessImageSyncRaw(::grpc::ClientContext* context, const ::MediaProcessorProcessImageRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MediaProcessorProcessImageResponse>::Create(channel_.get(), cq, rpcmethod_MediaProcessorProcessImageSync_, context, request, false);
}

::grpc::Status MediaProcessor::Stub::MediaProcessorProcessVideo(::grpc::ClientContext* context, const ::MediaProcessorProcessVideoRequest& request, ::MediaProcessorProcessVideoResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_MediaProcessorProcessVideo_, context, request, response);
}

void MediaProcessor::Stub::experimental_async::MediaProcessorProcessVideo(::grpc::ClientContext* context, const ::MediaProcessorProcessVideoRequest* request, ::MediaProcessorProcessVideoResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorProcessVideo_, context, request, response, std::move(f));
}

void MediaProcessor::Stub::experimental_async::MediaProcessorProcessVideo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MediaProcessorProcessVideoResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorProcessVideo_, context, request, response, std::move(f));
}

void MediaProcessor::Stub::experimental_async::MediaProcessorProcessVideo(::grpc::ClientContext* context, const ::MediaProcessorProcessVideoRequest* request, ::MediaProcessorProcessVideoResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorProcessVideo_, context, request, response, reactor);
}

void MediaProcessor::Stub::experimental_async::MediaProcessorProcessVideo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MediaProcessorProcessVideoResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorProcessVideo_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MediaProcessorProcessVideoResponse>* MediaProcessor::Stub::AsyncMediaProcessorProcessVideoRaw(::grpc::ClientContext* context, const ::MediaProcessorProcessVideoRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MediaProcessorProcessVideoResponse>::Create(channel_.get(), cq, rpcmethod_MediaProcessorProcessVideo_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::MediaProcessorProcessVideoResponse>* MediaProcessor::Stub::PrepareAsyncMediaProcessorProcessVideoRaw(::grpc::ClientContext* context, const ::MediaProcessorProcessVideoRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MediaProcessorProcessVideoResponse>::Create(channel_.get(), cq, rpcmethod_MediaProcessorProcessVideo_, context, request, false);
}

::grpc::Status MediaProcessor::Stub::MediaProcessorGetVideoThumbnail(::grpc::ClientContext* context, const ::MediaProcessorProcessVideoRequest& request, ::MediaProcessorProcessVideoResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_MediaProcessorGetVideoThumbnail_, context, request, response);
}

void MediaProcessor::Stub::experimental_async::MediaProcessorGetVideoThumbnail(::grpc::ClientContext* context, const ::MediaProcessorProcessVideoRequest* request, ::MediaProcessorProcessVideoResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorGetVideoThumbnail_, context, request, response, std::move(f));
}

void MediaProcessor::Stub::experimental_async::MediaProcessorGetVideoThumbnail(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MediaProcessorProcessVideoResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorGetVideoThumbnail_, context, request, response, std::move(f));
}

void MediaProcessor::Stub::experimental_async::MediaProcessorGetVideoThumbnail(::grpc::ClientContext* context, const ::MediaProcessorProcessVideoRequest* request, ::MediaProcessorProcessVideoResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorGetVideoThumbnail_, context, request, response, reactor);
}

void MediaProcessor::Stub::experimental_async::MediaProcessorGetVideoThumbnail(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MediaProcessorProcessVideoResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorGetVideoThumbnail_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MediaProcessorProcessVideoResponse>* MediaProcessor::Stub::AsyncMediaProcessorGetVideoThumbnailRaw(::grpc::ClientContext* context, const ::MediaProcessorProcessVideoRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MediaProcessorProcessVideoResponse>::Create(channel_.get(), cq, rpcmethod_MediaProcessorGetVideoThumbnail_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::MediaProcessorProcessVideoResponse>* MediaProcessor::Stub::PrepareAsyncMediaProcessorGetVideoThumbnailRaw(::grpc::ClientContext* context, const ::MediaProcessorProcessVideoRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MediaProcessorProcessVideoResponse>::Create(channel_.get(), cq, rpcmethod_MediaProcessorGetVideoThumbnail_, context, request, false);
}

::grpc::Status MediaProcessor::Stub::MediaProcessorGetState(::grpc::ClientContext* context, const ::MediaProcessorGetStateRequest& request, ::MediaProcessorGetStateResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_MediaProcessorGetState_, context, request, response);
}

void MediaProcessor::Stub::experimental_async::MediaProcessorGetState(::grpc::ClientContext* context, const ::MediaProcessorGetStateRequest* request, ::MediaProcessorGetStateResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorGetState_, context, request, response, std::move(f));
}

void MediaProcessor::Stub::experimental_async::MediaProcessorGetState(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MediaProcessorGetStateResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorGetState_, context, request, response, std::move(f));
}

void MediaProcessor::Stub::experimental_async::MediaProcessorGetState(::grpc::ClientContext* context, const ::MediaProcessorGetStateRequest* request, ::MediaProcessorGetStateResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorGetState_, context, request, response, reactor);
}

void MediaProcessor::Stub::experimental_async::MediaProcessorGetState(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::MediaProcessorGetStateResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_MediaProcessorGetState_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MediaProcessorGetStateResponse>* MediaProcessor::Stub::AsyncMediaProcessorGetStateRaw(::grpc::ClientContext* context, const ::MediaProcessorGetStateRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MediaProcessorGetStateResponse>::Create(channel_.get(), cq, rpcmethod_MediaProcessorGetState_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::MediaProcessorGetStateResponse>* MediaProcessor::Stub::PrepareAsyncMediaProcessorGetStateRaw(::grpc::ClientContext* context, const ::MediaProcessorGetStateRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::MediaProcessorGetStateResponse>::Create(channel_.get(), cq, rpcmethod_MediaProcessorGetState_, context, request, false);
}

MediaProcessor::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MediaProcessor_method_names[0],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< MediaProcessor::Service, ::MediaProcessorProcessImageRequest, ::MediaProcessorProcessImageResponse>(
          [](MediaProcessor::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::MediaProcessorProcessImageRequest* req,
             ::grpc_impl::ServerWriter<::MediaProcessorProcessImageResponse>* writer) {
               return service->MediaProcessorProcessImage(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MediaProcessor_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MediaProcessor::Service, ::MediaProcessorProcessImageRequest, ::MediaProcessorProcessImageResponse>(
          [](MediaProcessor::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::MediaProcessorProcessImageRequest* req,
             ::MediaProcessorProcessImageResponse* resp) {
               return service->MediaProcessorProcessImageSync(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MediaProcessor_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MediaProcessor::Service, ::MediaProcessorProcessVideoRequest, ::MediaProcessorProcessVideoResponse>(
          [](MediaProcessor::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::MediaProcessorProcessVideoRequest* req,
             ::MediaProcessorProcessVideoResponse* resp) {
               return service->MediaProcessorProcessVideo(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MediaProcessor_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MediaProcessor::Service, ::MediaProcessorProcessVideoRequest, ::MediaProcessorProcessVideoResponse>(
          [](MediaProcessor::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::MediaProcessorProcessVideoRequest* req,
             ::MediaProcessorProcessVideoResponse* resp) {
               return service->MediaProcessorGetVideoThumbnail(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MediaProcessor_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MediaProcessor::Service, ::MediaProcessorGetStateRequest, ::MediaProcessorGetStateResponse>(
          [](MediaProcessor::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::MediaProcessorGetStateRequest* req,
             ::MediaProcessorGetStateResponse* resp) {
               return service->MediaProcessorGetState(ctx, req, resp);
             }, this)));
}

MediaProcessor::Service::~Service() {
}

::grpc::Status MediaProcessor::Service::MediaProcessorProcessImage(::grpc::ServerContext* context, const ::MediaProcessorProcessImageRequest* request, ::grpc::ServerWriter< ::MediaProcessorProcessImageResponse>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MediaProcessor::Service::MediaProcessorProcessImageSync(::grpc::ServerContext* context, const ::MediaProcessorProcessImageRequest* request, ::MediaProcessorProcessImageResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MediaProcessor::Service::MediaProcessorProcessVideo(::grpc::ServerContext* context, const ::MediaProcessorProcessVideoRequest* request, ::MediaProcessorProcessVideoResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MediaProcessor::Service::MediaProcessorGetVideoThumbnail(::grpc::ServerContext* context, const ::MediaProcessorProcessVideoRequest* request, ::MediaProcessorProcessVideoResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MediaProcessor::Service::MediaProcessorGetState(::grpc::ServerContext* context, const ::MediaProcessorGetStateRequest* request, ::MediaProcessorGetStateResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


