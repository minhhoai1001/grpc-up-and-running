// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: order_management.proto

#include "order_management.pb.h"
#include "order_management.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace ecommerce {

static const char* OrderManagement_method_names[] = {
  "/ecommerce.OrderManagement/addOrder",
  "/ecommerce.OrderManagement/getOrder",
  "/ecommerce.OrderManagement/searchOrders",
  "/ecommerce.OrderManagement/updateOrders",
  "/ecommerce.OrderManagement/processOrders",
};

std::unique_ptr< OrderManagement::Stub> OrderManagement::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< OrderManagement::Stub> stub(new OrderManagement::Stub(channel, options));
  return stub;
}

OrderManagement::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_addOrder_(OrderManagement_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getOrder_(OrderManagement_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_searchOrders_(OrderManagement_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_updateOrders_(OrderManagement_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  , rpcmethod_processOrders_(OrderManagement_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  {}

::grpc::Status OrderManagement::Stub::addOrder(::grpc::ClientContext* context, const ::ecommerce::Order& request, ::google::protobuf::StringValue* response) {
  return ::grpc::internal::BlockingUnaryCall< ::ecommerce::Order, ::google::protobuf::StringValue, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_addOrder_, context, request, response);
}

void OrderManagement::Stub::async::addOrder(::grpc::ClientContext* context, const ::ecommerce::Order* request, ::google::protobuf::StringValue* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::ecommerce::Order, ::google::protobuf::StringValue, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_addOrder_, context, request, response, std::move(f));
}

void OrderManagement::Stub::async::addOrder(::grpc::ClientContext* context, const ::ecommerce::Order* request, ::google::protobuf::StringValue* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_addOrder_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::StringValue>* OrderManagement::Stub::PrepareAsyncaddOrderRaw(::grpc::ClientContext* context, const ::ecommerce::Order& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::google::protobuf::StringValue, ::ecommerce::Order, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_addOrder_, context, request);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::StringValue>* OrderManagement::Stub::AsyncaddOrderRaw(::grpc::ClientContext* context, const ::ecommerce::Order& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncaddOrderRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OrderManagement::Stub::getOrder(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::ecommerce::Order* response) {
  return ::grpc::internal::BlockingUnaryCall< ::google::protobuf::StringValue, ::ecommerce::Order, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_getOrder_, context, request, response);
}

void OrderManagement::Stub::async::getOrder(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::ecommerce::Order* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::google::protobuf::StringValue, ::ecommerce::Order, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getOrder_, context, request, response, std::move(f));
}

void OrderManagement::Stub::async::getOrder(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::ecommerce::Order* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getOrder_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::ecommerce::Order>* OrderManagement::Stub::PrepareAsyncgetOrderRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::ecommerce::Order, ::google::protobuf::StringValue, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_getOrder_, context, request);
}

::grpc::ClientAsyncResponseReader< ::ecommerce::Order>* OrderManagement::Stub::AsyncgetOrderRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetOrderRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientReader< ::ecommerce::Order>* OrderManagement::Stub::searchOrdersRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request) {
  return ::grpc::internal::ClientReaderFactory< ::ecommerce::Order>::Create(channel_.get(), rpcmethod_searchOrders_, context, request);
}

void OrderManagement::Stub::async::searchOrders(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::grpc::ClientReadReactor< ::ecommerce::Order>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::ecommerce::Order>::Create(stub_->channel_.get(), stub_->rpcmethod_searchOrders_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::ecommerce::Order>* OrderManagement::Stub::AsyncsearchOrdersRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::ecommerce::Order>::Create(channel_.get(), cq, rpcmethod_searchOrders_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::ecommerce::Order>* OrderManagement::Stub::PrepareAsyncsearchOrdersRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::ecommerce::Order>::Create(channel_.get(), cq, rpcmethod_searchOrders_, context, request, false, nullptr);
}

::grpc::ClientWriter< ::ecommerce::Order>* OrderManagement::Stub::updateOrdersRaw(::grpc::ClientContext* context, ::google::protobuf::StringValue* response) {
  return ::grpc::internal::ClientWriterFactory< ::ecommerce::Order>::Create(channel_.get(), rpcmethod_updateOrders_, context, response);
}

void OrderManagement::Stub::async::updateOrders(::grpc::ClientContext* context, ::google::protobuf::StringValue* response, ::grpc::ClientWriteReactor< ::ecommerce::Order>* reactor) {
  ::grpc::internal::ClientCallbackWriterFactory< ::ecommerce::Order>::Create(stub_->channel_.get(), stub_->rpcmethod_updateOrders_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::ecommerce::Order>* OrderManagement::Stub::AsyncupdateOrdersRaw(::grpc::ClientContext* context, ::google::protobuf::StringValue* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::ecommerce::Order>::Create(channel_.get(), cq, rpcmethod_updateOrders_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::ecommerce::Order>* OrderManagement::Stub::PrepareAsyncupdateOrdersRaw(::grpc::ClientContext* context, ::google::protobuf::StringValue* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::ecommerce::Order>::Create(channel_.get(), cq, rpcmethod_updateOrders_, context, response, false, nullptr);
}

::grpc::ClientReaderWriter< ::google::protobuf::StringValue, ::ecommerce::CombinedShipment>* OrderManagement::Stub::processOrdersRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::google::protobuf::StringValue, ::ecommerce::CombinedShipment>::Create(channel_.get(), rpcmethod_processOrders_, context);
}

void OrderManagement::Stub::async::processOrders(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::google::protobuf::StringValue,::ecommerce::CombinedShipment>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::google::protobuf::StringValue,::ecommerce::CombinedShipment>::Create(stub_->channel_.get(), stub_->rpcmethod_processOrders_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::google::protobuf::StringValue, ::ecommerce::CombinedShipment>* OrderManagement::Stub::AsyncprocessOrdersRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::google::protobuf::StringValue, ::ecommerce::CombinedShipment>::Create(channel_.get(), cq, rpcmethod_processOrders_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::google::protobuf::StringValue, ::ecommerce::CombinedShipment>* OrderManagement::Stub::PrepareAsyncprocessOrdersRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::google::protobuf::StringValue, ::ecommerce::CombinedShipment>::Create(channel_.get(), cq, rpcmethod_processOrders_, context, false, nullptr);
}

OrderManagement::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrderManagement_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OrderManagement::Service, ::ecommerce::Order, ::google::protobuf::StringValue, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OrderManagement::Service* service,
             ::grpc::ServerContext* ctx,
             const ::ecommerce::Order* req,
             ::google::protobuf::StringValue* resp) {
               return service->addOrder(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrderManagement_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OrderManagement::Service, ::google::protobuf::StringValue, ::ecommerce::Order, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OrderManagement::Service* service,
             ::grpc::ServerContext* ctx,
             const ::google::protobuf::StringValue* req,
             ::ecommerce::Order* resp) {
               return service->getOrder(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrderManagement_method_names[2],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< OrderManagement::Service, ::google::protobuf::StringValue, ::ecommerce::Order>(
          [](OrderManagement::Service* service,
             ::grpc::ServerContext* ctx,
             const ::google::protobuf::StringValue* req,
             ::grpc::ServerWriter<::ecommerce::Order>* writer) {
               return service->searchOrders(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrderManagement_method_names[3],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< OrderManagement::Service, ::ecommerce::Order, ::google::protobuf::StringValue>(
          [](OrderManagement::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReader<::ecommerce::Order>* reader,
             ::google::protobuf::StringValue* resp) {
               return service->updateOrders(ctx, reader, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrderManagement_method_names[4],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< OrderManagement::Service, ::google::protobuf::StringValue, ::ecommerce::CombinedShipment>(
          [](OrderManagement::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::ecommerce::CombinedShipment,
             ::google::protobuf::StringValue>* stream) {
               return service->processOrders(ctx, stream);
             }, this)));
}

OrderManagement::Service::~Service() {
}

::grpc::Status OrderManagement::Service::addOrder(::grpc::ServerContext* context, const ::ecommerce::Order* request, ::google::protobuf::StringValue* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OrderManagement::Service::getOrder(::grpc::ServerContext* context, const ::google::protobuf::StringValue* request, ::ecommerce::Order* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OrderManagement::Service::searchOrders(::grpc::ServerContext* context, const ::google::protobuf::StringValue* request, ::grpc::ServerWriter< ::ecommerce::Order>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OrderManagement::Service::updateOrders(::grpc::ServerContext* context, ::grpc::ServerReader< ::ecommerce::Order>* reader, ::google::protobuf::StringValue* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OrderManagement::Service::processOrders(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::ecommerce::CombinedShipment, ::google::protobuf::StringValue>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace ecommerce

