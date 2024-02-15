// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: product_info.proto

#include "product_info.pb.h"
#include "product_info.grpc.pb.h"

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
namespace ecommerce {

static const char* ProductInfo_method_names[] = {
  "/ecommerce.ProductInfo/addProduct",
  "/ecommerce.ProductInfo/getProduct",
};

std::unique_ptr< ProductInfo::Stub> ProductInfo::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ProductInfo::Stub> stub(new ProductInfo::Stub(channel));
  return stub;
}

ProductInfo::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_addProduct_(ProductInfo_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getProduct_(ProductInfo_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ProductInfo::Stub::addProduct(::grpc::ClientContext* context, const ::ecommerce::Product& request, ::ecommerce::ProductID* response) {
  return ::grpc::internal::BlockingUnaryCall< ::ecommerce::Product, ::ecommerce::ProductID, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_addProduct_, context, request, response);
}

void ProductInfo::Stub::experimental_async::addProduct(::grpc::ClientContext* context, const ::ecommerce::Product* request, ::ecommerce::ProductID* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::ecommerce::Product, ::ecommerce::ProductID, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_addProduct_, context, request, response, std::move(f));
}

void ProductInfo::Stub::experimental_async::addProduct(::grpc::ClientContext* context, const ::ecommerce::Product* request, ::ecommerce::ProductID* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_addProduct_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::ecommerce::ProductID>* ProductInfo::Stub::PrepareAsyncaddProductRaw(::grpc::ClientContext* context, const ::ecommerce::Product& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::ecommerce::ProductID, ::ecommerce::Product, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_addProduct_, context, request);
}

::grpc::ClientAsyncResponseReader< ::ecommerce::ProductID>* ProductInfo::Stub::AsyncaddProductRaw(::grpc::ClientContext* context, const ::ecommerce::Product& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncaddProductRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status ProductInfo::Stub::getProduct(::grpc::ClientContext* context, const ::ecommerce::ProductID& request, ::ecommerce::Product* response) {
  return ::grpc::internal::BlockingUnaryCall< ::ecommerce::ProductID, ::ecommerce::Product, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_getProduct_, context, request, response);
}

void ProductInfo::Stub::experimental_async::getProduct(::grpc::ClientContext* context, const ::ecommerce::ProductID* request, ::ecommerce::Product* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::ecommerce::ProductID, ::ecommerce::Product, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getProduct_, context, request, response, std::move(f));
}

void ProductInfo::Stub::experimental_async::getProduct(::grpc::ClientContext* context, const ::ecommerce::ProductID* request, ::ecommerce::Product* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getProduct_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::ecommerce::Product>* ProductInfo::Stub::PrepareAsyncgetProductRaw(::grpc::ClientContext* context, const ::ecommerce::ProductID& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::ecommerce::Product, ::ecommerce::ProductID, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_getProduct_, context, request);
}

::grpc::ClientAsyncResponseReader< ::ecommerce::Product>* ProductInfo::Stub::AsyncgetProductRaw(::grpc::ClientContext* context, const ::ecommerce::ProductID& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetProductRaw(context, request, cq);
  result->StartCall();
  return result;
}

ProductInfo::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ProductInfo_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ProductInfo::Service, ::ecommerce::Product, ::ecommerce::ProductID, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ProductInfo::Service* service,
             ::grpc::ServerContext* ctx,
             const ::ecommerce::Product* req,
             ::ecommerce::ProductID* resp) {
               return service->addProduct(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ProductInfo_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ProductInfo::Service, ::ecommerce::ProductID, ::ecommerce::Product, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ProductInfo::Service* service,
             ::grpc::ServerContext* ctx,
             const ::ecommerce::ProductID* req,
             ::ecommerce::Product* resp) {
               return service->getProduct(ctx, req, resp);
             }, this)));
}

ProductInfo::Service::~Service() {
}

::grpc::Status ProductInfo::Service::addProduct(::grpc::ServerContext* context, const ::ecommerce::Product* request, ::ecommerce::ProductID* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ProductInfo::Service::getProduct(::grpc::ServerContext* context, const ::ecommerce::ProductID* request, ::ecommerce::Product* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace ecommerce

