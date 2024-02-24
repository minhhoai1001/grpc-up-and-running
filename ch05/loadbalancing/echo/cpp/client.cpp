#include <iostream>
#include <memory>
#include <thread>
#include <grpcpp/grpcpp.h>
#include "echo/echo.pb.h"
#include "echo/echo.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using grpc::ChannelArguments;
using echo::EchoRequest;
using echo::EchoResponse;
using echo::Echo;

class EchoClient 
{
public:
    EchoClient(std::shared_ptr<Channel> channel) : stub_(Echo::NewStub(channel)) {}

    std::string callUnaryEcho(const std::string& message)
    {
        EchoRequest request;
        request.set_message(message);
        EchoResponse response;
        ClientContext context;

        auto deadline = std::chrono::system_clock::now() + std::chrono::seconds(2);
        context.set_deadline(deadline);
        Status status = stub_->UnaryEcho(&context, request, &response);
        
        if (status.ok()) {
            return response.message();
        } else {
            std::cout << "Error: " << status.error_code() << " - " << status.error_message() << std::endl;
            return "";
        }
    }

private:
    std::unique_ptr<Echo::Stub> stub_;
};

void makeRPCs(EchoClient& echo, int n) {
    for (int i = 0; i < n; ++i) {
        std::string message = echo.callUnaryEcho("this is examples/load_balancing");
        std::cout << message <<std::endl;
    }
}

int main() 
{
    EchoClient pick_first(grpc::CreateChannel(
        "localhost:50051", grpc::InsecureChannelCredentials()));
    std::cout << "--- calling helloworld.Greeter/SayHello with pick_first ---" << std::endl;
    makeRPCs(pick_first, 10); 

    ChannelArguments args;
    // Set the load balancing policy for the channel.
    args.SetLoadBalancingPolicyName("round_robin");
    EchoClient round_robin(grpc::CreateCustomChannel(
        "localhost:50052", grpc::InsecureChannelCredentials(), args));

    std::cout << "--- calling helloworld.Greeter/SayHello with round_robin ---" << std::endl;
    makeRPCs(round_robin, 10);
    return 0;
}
