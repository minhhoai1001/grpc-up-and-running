#include <iostream>
#include <memory>
#include <thread>
#include <grpcpp/grpcpp.h>
#include "ecommerce/order_management.pb.h"
#include "ecommerce/order_management.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using ecommerce::Order;
using ecommerce::CombinedShipment;
using ecommerce::OrderManagement;
using google::protobuf::StringValue;

class OrderManagementClient 
{
public:
    OrderManagementClient(std::shared_ptr<Channel> channel) : stub_(OrderManagement::NewStub(channel)) {}

    std::string AddOrder(const Order& order) 
    {
        StringValue response;
        ClientContext context;
        Status status = stub_->addOrder(&context, order, &response);
        if (status.ok()) {
            return response.value();
        } else {
            std::cout << "Error: " << status.error_code() << ": " << status.error_message() << std::endl;
            return "";
        }
    }
    
    int GetOrder(const std::string& id, Order* response) 
    {
        StringValue request;
        request.set_value(id);
        ClientContext context;
        Status status = stub_->getOrder(&context, request, response);
        if (status.ok()) 
        {
            return 0;
        } else 
        {
            std::cout << "Error: " << status.error_code() << ": " << status.error_message() << std::endl;
            return -1;
        }
    }

    int SearchOrders(const std::string& searchItem, std::vector<Order>& orders) 
    {
        ClientContext context;
        StringValue request;
        request.set_value(searchItem);
        std::unique_ptr<grpc::ClientReader<Order>> reader(stub_->searchOrders(&context, request));

        Order order;
        while (reader->Read(&order)) {
            // Process each order received
            orders.push_back(order);
        }

        Status status = reader->Finish();
        if (!status.ok()) {
            std::cout << "RPC failed: " << status.error_message() << std::endl;
            return -1;
        }

        return 0;
    }

    int UpdateOrders(std::vector<Order>& orders)
    {
        ClientContext context;
        StringValue request;
        std::unique_ptr<grpc::ClientWriter<Order>> writer(stub_->updateOrders(&context, &request));

        for (auto order: orders)
        {
            writer->Write(order);
        }
        writer->WritesDone();
        Status status = writer->Finish();

        if (!status.ok()) {
            std::cout << "RPC failed: " << status.error_message() << std::endl;
            return -1;
        }
        return 0;
    }

    int ProcessOrder(std::vector<std::string>& orderIDs, std::vector<Order>& orders)
    {
        ClientContext context;
        std::shared_ptr<grpc::ClientReaderWriter<StringValue, CombinedShipment>> stream(stub_->processOrders(&context));

        for (const std::string& orderID : orderIDs) {
            StringValue request;
            request.set_value(orderID);

            if (!stream->Write(request)) {
                break;
            }
        }

        std::thread async_thread([&]() {
            while (!done_) {
                CombinedShipment response;
                if (stream->Read(&response)) {
                    // Process CombinedShipment response here
                    std::cout << "Received CombinedShipment ID: " << response.id() << std::endl;
                    for(auto order: response.orderslist())
                    {
                        orders.push_back(order);
                    }
                } else {
                    break;
                }
            }
        });

        stream->WritesDone();

        std::this_thread::sleep_for(std::chrono::seconds(1)); // Cancel after 1 seconds
        context.TryCancel();

        async_thread.join();
        Status status = stream->Finish();
        if (!status.ok()) {
            std::cout << "RPC failed: " << status.error_message() << std::endl;
            done_ = true;
            return -1;
        }

        return 0;
    }

private:
    std::unique_ptr<OrderManagement::Stub> stub_;
    bool done_ = false;
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
    // Create a client
    OrderManagementClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));

    std::vector<std::string> orderIDs = {"102", "103", "104"};
    std::vector<Order> orders;
    int error = client.ProcessOrder(orderIDs, orders);
    for (auto order : orders)
    {
        printOrder(order);
    }

    // Sending additional order ID after 1 second
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::vector<std::string> additionOrderIDs = {"101", "105", "106"};
    std::vector<Order> additionOrders;
    error = client.ProcessOrder(additionOrderIDs, additionOrders);
    for (auto order : additionOrders)
    {
        printOrder(order);
    }

    return 0;
}
