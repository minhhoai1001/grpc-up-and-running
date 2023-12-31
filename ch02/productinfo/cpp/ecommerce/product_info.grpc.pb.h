// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: product_info.proto
#ifndef GRPC_product_5finfo_2eproto__INCLUDED
#define GRPC_product_5finfo_2eproto__INCLUDED

#include "product_info.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

namespace ecommerce {

class ProductInfo final {
 public:
  static constexpr char const* service_full_name() {
    return "ecommerce.ProductInfo";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status addProduct(::grpc::ClientContext* context, const ::ecommerce::Product& request, ::ecommerce::ProductID* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::ecommerce::ProductID>> AsyncaddProduct(::grpc::ClientContext* context, const ::ecommerce::Product& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::ecommerce::ProductID>>(AsyncaddProductRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::ecommerce::ProductID>> PrepareAsyncaddProduct(::grpc::ClientContext* context, const ::ecommerce::Product& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::ecommerce::ProductID>>(PrepareAsyncaddProductRaw(context, request, cq));
    }
    virtual ::grpc::Status getProduct(::grpc::ClientContext* context, const ::ecommerce::ProductID& request, ::ecommerce::Product* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::ecommerce::Product>> AsyncgetProduct(::grpc::ClientContext* context, const ::ecommerce::ProductID& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::ecommerce::Product>>(AsyncgetProductRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::ecommerce::Product>> PrepareAsyncgetProduct(::grpc::ClientContext* context, const ::ecommerce::ProductID& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::ecommerce::Product>>(PrepareAsyncgetProductRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void addProduct(::grpc::ClientContext* context, const ::ecommerce::Product* request, ::ecommerce::ProductID* response, std::function<void(::grpc::Status)>) = 0;
      virtual void addProduct(::grpc::ClientContext* context, const ::ecommerce::Product* request, ::ecommerce::ProductID* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void getProduct(::grpc::ClientContext* context, const ::ecommerce::ProductID* request, ::ecommerce::Product* response, std::function<void(::grpc::Status)>) = 0;
      virtual void getProduct(::grpc::ClientContext* context, const ::ecommerce::ProductID* request, ::ecommerce::Product* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::ecommerce::ProductID>* AsyncaddProductRaw(::grpc::ClientContext* context, const ::ecommerce::Product& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::ecommerce::ProductID>* PrepareAsyncaddProductRaw(::grpc::ClientContext* context, const ::ecommerce::Product& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::ecommerce::Product>* AsyncgetProductRaw(::grpc::ClientContext* context, const ::ecommerce::ProductID& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::ecommerce::Product>* PrepareAsyncgetProductRaw(::grpc::ClientContext* context, const ::ecommerce::ProductID& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status addProduct(::grpc::ClientContext* context, const ::ecommerce::Product& request, ::ecommerce::ProductID* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::ecommerce::ProductID>> AsyncaddProduct(::grpc::ClientContext* context, const ::ecommerce::Product& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::ecommerce::ProductID>>(AsyncaddProductRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::ecommerce::ProductID>> PrepareAsyncaddProduct(::grpc::ClientContext* context, const ::ecommerce::Product& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::ecommerce::ProductID>>(PrepareAsyncaddProductRaw(context, request, cq));
    }
    ::grpc::Status getProduct(::grpc::ClientContext* context, const ::ecommerce::ProductID& request, ::ecommerce::Product* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::ecommerce::Product>> AsyncgetProduct(::grpc::ClientContext* context, const ::ecommerce::ProductID& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::ecommerce::Product>>(AsyncgetProductRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::ecommerce::Product>> PrepareAsyncgetProduct(::grpc::ClientContext* context, const ::ecommerce::ProductID& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::ecommerce::Product>>(PrepareAsyncgetProductRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void addProduct(::grpc::ClientContext* context, const ::ecommerce::Product* request, ::ecommerce::ProductID* response, std::function<void(::grpc::Status)>) override;
      void addProduct(::grpc::ClientContext* context, const ::ecommerce::Product* request, ::ecommerce::ProductID* response, ::grpc::ClientUnaryReactor* reactor) override;
      void getProduct(::grpc::ClientContext* context, const ::ecommerce::ProductID* request, ::ecommerce::Product* response, std::function<void(::grpc::Status)>) override;
      void getProduct(::grpc::ClientContext* context, const ::ecommerce::ProductID* request, ::ecommerce::Product* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::ecommerce::ProductID>* AsyncaddProductRaw(::grpc::ClientContext* context, const ::ecommerce::Product& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::ecommerce::ProductID>* PrepareAsyncaddProductRaw(::grpc::ClientContext* context, const ::ecommerce::Product& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::ecommerce::Product>* AsyncgetProductRaw(::grpc::ClientContext* context, const ::ecommerce::ProductID& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::ecommerce::Product>* PrepareAsyncgetProductRaw(::grpc::ClientContext* context, const ::ecommerce::ProductID& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_addProduct_;
    const ::grpc::internal::RpcMethod rpcmethod_getProduct_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status addProduct(::grpc::ServerContext* context, const ::ecommerce::Product* request, ::ecommerce::ProductID* response);
    virtual ::grpc::Status getProduct(::grpc::ServerContext* context, const ::ecommerce::ProductID* request, ::ecommerce::Product* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_addProduct : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_addProduct() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_addProduct() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status addProduct(::grpc::ServerContext* /*context*/, const ::ecommerce::Product* /*request*/, ::ecommerce::ProductID* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestaddProduct(::grpc::ServerContext* context, ::ecommerce::Product* request, ::grpc::ServerAsyncResponseWriter< ::ecommerce::ProductID>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_getProduct : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_getProduct() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_getProduct() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getProduct(::grpc::ServerContext* /*context*/, const ::ecommerce::ProductID* /*request*/, ::ecommerce::Product* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestgetProduct(::grpc::ServerContext* context, ::ecommerce::ProductID* request, ::grpc::ServerAsyncResponseWriter< ::ecommerce::Product>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_addProduct<WithAsyncMethod_getProduct<Service > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_addProduct : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_addProduct() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::ecommerce::Product, ::ecommerce::ProductID>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::ecommerce::Product* request, ::ecommerce::ProductID* response) { return this->addProduct(context, request, response); }));}
    void SetMessageAllocatorFor_addProduct(
        ::grpc::MessageAllocator< ::ecommerce::Product, ::ecommerce::ProductID>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::ecommerce::Product, ::ecommerce::ProductID>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_addProduct() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status addProduct(::grpc::ServerContext* /*context*/, const ::ecommerce::Product* /*request*/, ::ecommerce::ProductID* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* addProduct(
      ::grpc::CallbackServerContext* /*context*/, const ::ecommerce::Product* /*request*/, ::ecommerce::ProductID* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_getProduct : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_getProduct() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::ecommerce::ProductID, ::ecommerce::Product>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::ecommerce::ProductID* request, ::ecommerce::Product* response) { return this->getProduct(context, request, response); }));}
    void SetMessageAllocatorFor_getProduct(
        ::grpc::MessageAllocator< ::ecommerce::ProductID, ::ecommerce::Product>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::ecommerce::ProductID, ::ecommerce::Product>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_getProduct() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getProduct(::grpc::ServerContext* /*context*/, const ::ecommerce::ProductID* /*request*/, ::ecommerce::Product* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* getProduct(
      ::grpc::CallbackServerContext* /*context*/, const ::ecommerce::ProductID* /*request*/, ::ecommerce::Product* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_addProduct<WithCallbackMethod_getProduct<Service > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_addProduct : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_addProduct() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_addProduct() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status addProduct(::grpc::ServerContext* /*context*/, const ::ecommerce::Product* /*request*/, ::ecommerce::ProductID* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_getProduct : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_getProduct() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_getProduct() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getProduct(::grpc::ServerContext* /*context*/, const ::ecommerce::ProductID* /*request*/, ::ecommerce::Product* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_addProduct : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_addProduct() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_addProduct() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status addProduct(::grpc::ServerContext* /*context*/, const ::ecommerce::Product* /*request*/, ::ecommerce::ProductID* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestaddProduct(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_getProduct : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_getProduct() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_getProduct() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getProduct(::grpc::ServerContext* /*context*/, const ::ecommerce::ProductID* /*request*/, ::ecommerce::Product* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestgetProduct(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_addProduct : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_addProduct() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->addProduct(context, request, response); }));
    }
    ~WithRawCallbackMethod_addProduct() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status addProduct(::grpc::ServerContext* /*context*/, const ::ecommerce::Product* /*request*/, ::ecommerce::ProductID* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* addProduct(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_getProduct : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_getProduct() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->getProduct(context, request, response); }));
    }
    ~WithRawCallbackMethod_getProduct() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getProduct(::grpc::ServerContext* /*context*/, const ::ecommerce::ProductID* /*request*/, ::ecommerce::Product* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* getProduct(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_addProduct : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_addProduct() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::ecommerce::Product, ::ecommerce::ProductID>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::ecommerce::Product, ::ecommerce::ProductID>* streamer) {
                       return this->StreamedaddProduct(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_addProduct() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status addProduct(::grpc::ServerContext* /*context*/, const ::ecommerce::Product* /*request*/, ::ecommerce::ProductID* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedaddProduct(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::ecommerce::Product,::ecommerce::ProductID>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_getProduct : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_getProduct() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::ecommerce::ProductID, ::ecommerce::Product>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::ecommerce::ProductID, ::ecommerce::Product>* streamer) {
                       return this->StreamedgetProduct(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_getProduct() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status getProduct(::grpc::ServerContext* /*context*/, const ::ecommerce::ProductID* /*request*/, ::ecommerce::Product* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedgetProduct(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::ecommerce::ProductID,::ecommerce::Product>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_addProduct<WithStreamedUnaryMethod_getProduct<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_addProduct<WithStreamedUnaryMethod_getProduct<Service > > StreamedService;
};

}  // namespace ecommerce


#endif  // GRPC_product_5finfo_2eproto__INCLUDED
