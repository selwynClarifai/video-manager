// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: proto/blur/blur_extent.proto
#ifndef GRPC_proto_2fblur_2fblur_5fextent_2eproto__INCLUDED
#define GRPC_proto_2fblur_2fblur_5fextent_2eproto__INCLUDED

#include "proto/blur/blur_extent.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

class BlurDetectionService final {
 public:
  static constexpr char const* service_full_name() {
    return "BlurDetectionService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status BlurDetect(::grpc::ClientContext* context, const ::BlurDetectRequest& request, ::BlurDetectResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::BlurDetectResponse>> AsyncBlurDetect(::grpc::ClientContext* context, const ::BlurDetectRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::BlurDetectResponse>>(AsyncBlurDetectRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::BlurDetectResponse>> PrepareAsyncBlurDetect(::grpc::ClientContext* context, const ::BlurDetectRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::BlurDetectResponse>>(PrepareAsyncBlurDetectRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void BlurDetect(::grpc::ClientContext* context, const ::BlurDetectRequest* request, ::BlurDetectResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void BlurDetect(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::BlurDetectResponse* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void BlurDetect(::grpc::ClientContext* context, const ::BlurDetectRequest* request, ::BlurDetectResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void BlurDetect(::grpc::ClientContext* context, const ::BlurDetectRequest* request, ::BlurDetectResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void BlurDetect(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::BlurDetectResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void BlurDetect(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::BlurDetectResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::BlurDetectResponse>* AsyncBlurDetectRaw(::grpc::ClientContext* context, const ::BlurDetectRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::BlurDetectResponse>* PrepareAsyncBlurDetectRaw(::grpc::ClientContext* context, const ::BlurDetectRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status BlurDetect(::grpc::ClientContext* context, const ::BlurDetectRequest& request, ::BlurDetectResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::BlurDetectResponse>> AsyncBlurDetect(::grpc::ClientContext* context, const ::BlurDetectRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::BlurDetectResponse>>(AsyncBlurDetectRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::BlurDetectResponse>> PrepareAsyncBlurDetect(::grpc::ClientContext* context, const ::BlurDetectRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::BlurDetectResponse>>(PrepareAsyncBlurDetectRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void BlurDetect(::grpc::ClientContext* context, const ::BlurDetectRequest* request, ::BlurDetectResponse* response, std::function<void(::grpc::Status)>) override;
      void BlurDetect(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::BlurDetectResponse* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void BlurDetect(::grpc::ClientContext* context, const ::BlurDetectRequest* request, ::BlurDetectResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void BlurDetect(::grpc::ClientContext* context, const ::BlurDetectRequest* request, ::BlurDetectResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void BlurDetect(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::BlurDetectResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void BlurDetect(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::BlurDetectResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::BlurDetectResponse>* AsyncBlurDetectRaw(::grpc::ClientContext* context, const ::BlurDetectRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::BlurDetectResponse>* PrepareAsyncBlurDetectRaw(::grpc::ClientContext* context, const ::BlurDetectRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_BlurDetect_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status BlurDetect(::grpc::ServerContext* context, const ::BlurDetectRequest* request, ::BlurDetectResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_BlurDetect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_BlurDetect() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_BlurDetect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BlurDetect(::grpc::ServerContext* /*context*/, const ::BlurDetectRequest* /*request*/, ::BlurDetectResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestBlurDetect(::grpc::ServerContext* context, ::BlurDetectRequest* request, ::grpc::ServerAsyncResponseWriter< ::BlurDetectResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_BlurDetect<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_BlurDetect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_BlurDetect() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::BlurDetectRequest, ::BlurDetectResponse>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::BlurDetectRequest* request, ::BlurDetectResponse* response) { return this->BlurDetect(context, request, response); }));}
    void SetMessageAllocatorFor_BlurDetect(
        ::grpc::experimental::MessageAllocator< ::BlurDetectRequest, ::BlurDetectResponse>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(0);
    #endif
      static_cast<::grpc_impl::internal::CallbackUnaryHandler< ::BlurDetectRequest, ::BlurDetectResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_BlurDetect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BlurDetect(::grpc::ServerContext* /*context*/, const ::BlurDetectRequest* /*request*/, ::BlurDetectResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* BlurDetect(
      ::grpc::CallbackServerContext* /*context*/, const ::BlurDetectRequest* /*request*/, ::BlurDetectResponse* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* BlurDetect(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::BlurDetectRequest* /*request*/, ::BlurDetectResponse* /*response*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_BlurDetect<Service > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_BlurDetect<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_BlurDetect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_BlurDetect() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_BlurDetect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BlurDetect(::grpc::ServerContext* /*context*/, const ::BlurDetectRequest* /*request*/, ::BlurDetectResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_BlurDetect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_BlurDetect() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_BlurDetect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BlurDetect(::grpc::ServerContext* /*context*/, const ::BlurDetectRequest* /*request*/, ::BlurDetectResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestBlurDetect(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_BlurDetect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_BlurDetect() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->BlurDetect(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_BlurDetect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BlurDetect(::grpc::ServerContext* /*context*/, const ::BlurDetectRequest* /*request*/, ::BlurDetectResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* BlurDetect(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* BlurDetect(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_BlurDetect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_BlurDetect() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::BlurDetectRequest, ::BlurDetectResponse>(
            [this](::grpc_impl::ServerContext* context,
                   ::grpc_impl::ServerUnaryStreamer<
                     ::BlurDetectRequest, ::BlurDetectResponse>* streamer) {
                       return this->StreamedBlurDetect(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_BlurDetect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status BlurDetect(::grpc::ServerContext* /*context*/, const ::BlurDetectRequest* /*request*/, ::BlurDetectResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedBlurDetect(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::BlurDetectRequest,::BlurDetectResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_BlurDetect<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_BlurDetect<Service > StreamedService;
};


#endif  // GRPC_proto_2fblur_2fblur_5fextent_2eproto__INCLUDED
