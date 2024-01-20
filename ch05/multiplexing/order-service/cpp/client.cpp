#include <iostream>
#include <memory>
#include <thread>
#include <grpcpp/grpcpp.h>
#include "ecommerce/order_management.pb.h"
#include "ecommerce/order_management.grpc.pb.h"
#include "ecommerce/helloworld.pb.h"
#include "ecommerce/helloworld.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using ecommerce::Order;
using ecommerce::CombinedShipment;
using ecommerce::OrderManagement;
using google::protobuf::StringValue;

using helloworld::Greeter;
using helloworld::HelloReply;
using helloworld::HelloRequest;

class OrderManagementClient 
{
public:
    OrderManagementClient(std::shared_ptr<Channel> channel) : stub_(OrderManagement::NewStub(channel)) {}

    std::string AddOrder(const Order& order) 
    {
        StringValue response;
        ClientContext context;
        auto deadline = std::chrono::system_clock::now() + std::chrono::seconds(2);
        context.set_deadline(deadline);
        Status status = stub_->addOrder(&context, order, &response);
        if (status.ok()) {
            return response.value();
        } else {
            std::cout << "Error: " << status.error_code() << ": " << status.error_message() << std::endl;
            return "";
        }
    }

private:
    std::unique_ptr<OrderManagement::Stub> stub_;
};

class HelloWorldClient 
{
public:
    HelloWorldClient(std::shared_ptr<Channel> channel) : stub_(Greeter::NewStub(channel)) {}

    std::string SayHello(const std::string& name) 
    {
        HelloRequest request;
        request.set_name(name);

        HelloReply response;
        ClientContext context;

        // Make the RPC call
        Status status = stub_->SayHello(&context, request, &response);

        // Check the status of the RPC
        if (status.ok()) {
            return response.message();
        } else {
            std::cerr << "RPC failed: " << status.error_message() << std::endl;
            return "";
        }
    }

private:
    std::unique_ptr<Greeter::Stub> stub_;
};

void printOrder(const Order& order)
{
    std::cout << "----- Product -----" << std::endl;
    std::cout << "Order ID: " << order.id() << std::endl;
    std::cout << "Items: ";
    for (const std::string& item : order.items()) {
        std::cout << item << ", ";
    }
    std::cout << std::endl;
    std::cout << "Description: " << order.description() << std::endl;
    std::cout << "Price: " << order.price() << std::endl;
    std::cout << "Destination: " << order.destination() << std::endl;
}

int main() 
{
    auto channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());

    // *********** Calling the Order Management gRPC service **********
    OrderManagementClient client(channel);
    Order order;
    order.set_id("101");
    order.add_items("iPhone XS");
    order.add_items("Mac Book Pro");
    order.set_destination("San Jose, CA");
    order.set_price(2300.00);
    
    std::string addedOrderID = client.AddOrder(order);
    if (!addedOrderID.empty()) 
    {
        std::cout << "Product ID: " << addedOrderID << " added successfully \n";
    }

    // *********** Calling the Greeter gRPC service  **********
    HelloWorldClient helloClient(channel);
    std::string name = "user";
    
    std::string helloResponse = helloClient.SayHello(name);
    if (!helloResponse.empty()) 
    {
        std::cout << "Hello response: " << helloResponse << std::endl;
    }

    return 0;
}
