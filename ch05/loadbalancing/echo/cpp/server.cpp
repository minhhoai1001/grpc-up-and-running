#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <grpcpp/grpcpp.h>
#include "echo/echo.pb.h"
#include "echo/echo.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::StatusCode;
using echo::EchoRequest;
using echo::EchoResponse;
using echo::Echo;

class EchoServerImpl final : public Echo::Service {
public:
    // UnaryEcho is unary echo.
    Status UnaryEcho(ServerContext* context, const EchoRequest* request, EchoResponse* response) override 
    {
        response->set_message(request->message()+ " (from " + context->peer() + ")");
        
        return Status::OK;
    }

    Status ServerStreamingEcho(ServerContext* context, const EchoRequest* request, grpc::ServerWriter< EchoResponse>* writer) override
    {
        return Status(StatusCode::UNIMPLEMENTED, "not implemented");
    }
    
    // ClientStreamingEcho is client side streaming.
    Status ClientStreamingEcho(ServerContext* context, grpc::ServerReader< EchoRequest>* reader, EchoResponse* response) override
    {
        return Status(StatusCode::UNIMPLEMENTED, "not implemented");
    }
    
    // BidirectionalStreamingEcho is bidi streaming.
    Status BidirectionalStreamingEcho(ServerContext* context, grpc::ServerReaderWriter< EchoResponse, EchoRequest>* stream) override
    {
        return Status(StatusCode::UNIMPLEMENTED, "not implemented");
    }
private:

};

void RunServer(const std::string& server_address) {
  EchoServerImpl service;

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}

int main(int argc, char** argv) {
  std::string server_address_1("0.0.0.0:50051");
  std::string server_address_2("0.0.0.0:50052");

  std::thread t1(RunServer, server_address_1);
  std::thread t2(RunServer, server_address_2);

  t1.join();
  t2.join();

  return 0;
}