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
        auto currentTime = std::chrono::system_clock::now();
        std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
        std::string currentTimeString = formatTime(currentTime_t);
        context.AddMetadata("timestamp", currentTimeString);
        Status status = stub_->addOrder(&context, order, &response);
        if (status.ok()) {
            const std::multimap<grpc::string_ref, grpc::string_ref> metadata = context.GetServerInitialMetadata();
            for (auto iter = metadata.begin(); iter != metadata.end(); ++iter) {
                if (iter->first == "location")
                {
                    std::cout << "==> location from header: " << iter->second <<std::endl;
                }
                else if (iter->first == "timestamp")
                {
                    std::cout << "==> location from header: " << iter->second <<std::endl;
                }
                else 
                {
                    std::cout << "location and timestamp expected but doesn't exist in header\n";
                }
            }
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
            while (true) {
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
        async_thread.join();
        Status status = stream->Finish();
        if (!status.ok()) {
            std::cout << "RPC failed: " << status.error_message() << std::endl;
            return -1;
        }

        return 0;
    }

private:
    std::unique_ptr<OrderManagement::Stub> stub_;

    std::string formatTime(std::time_t time) 
    {
        std::tm* tm_info = std::localtime(&time);
        std::ostringstream oss;
        oss << std::put_time(tm_info, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }
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

    while (true) 
    {
        std::string text;
        std::cout << "Enter a choice (add-order, get-order, search, update, process, exit): ";
        std::getline(std::cin, text);
        
        if (text == "add-order") 
        {
            // Add Order
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
        }
        else if (text == "get-order") 
        {
            std::string id {"101"};
            Order retrievedOrder;
            int error = client.GetOrder(id, &retrievedOrder);
            if (error != 0 || retrievedOrder.id().empty())
            {
                std::cout << "Could not get product \n";
                continue;
            }
            printOrder(retrievedOrder);
        }
        else if (text == "search") 
        {
            std::vector<Order> orders;
            std::string search {"Microsoft"};
            int error = client.SearchOrders(search, orders);
            if (error != 0 || orders.size() == 0)
            {
                std::cout << "Could not found order \n";
                continue;
            }

            for (auto order : orders)
            {
                printOrder(order);
            }
        }
        else if (text == "update")
        {
            std::vector<Order> orders;
            Order updOrder1;
            updOrder1.set_id("102");
            updOrder1.add_items("Google Pixel 3A");
            updOrder1.add_items("Google Pixel Book");
            updOrder1.set_destination("Mountain View, CA");
            updOrder1.set_price(1100.00);
            orders.push_back(updOrder1);

            Order updOrder2;
            updOrder2.set_id("103");
            updOrder2.add_items("Apple Watch S4");
            updOrder2.add_items("Mac Book Pro");
            updOrder2.add_items("iPad Pro");
            updOrder2.set_destination("San Jose, CA");
            updOrder2.set_price(2800.00);
            orders.push_back(updOrder2);

            Order updOrder3;
            updOrder3.set_id("104");
            updOrder3.add_items("Google Home Mini");
            updOrder3.add_items("Google Nest Hub");
            updOrder3.add_items("iPad Mini");
            updOrder3.set_destination("Mountain View, CA");
            updOrder3.set_price(2200.00);
            orders.push_back(updOrder3);

            int error = client.UpdateOrders(orders);
        }
        else if (text == "process")
        {
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
        }
        else break;
    }

    return 0;
}
