#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "ecommerce/order_management.pb.h"
#include "ecommerce/order_management.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::experimental::InterceptionHookPoints;
using grpc::experimental::Interceptor;
using grpc::experimental::InterceptorBatchMethods;
using grpc::experimental::ServerInterceptorFactoryInterface;
using grpc::experimental::ServerRpcInfo;
using ecommerce::Order;
using ecommerce::CombinedShipment;
using ecommerce::OrderManagement;
using google::protobuf::StringValue;

class OrderManagementServiceImpl final : public OrderManagement::Service {
public:
    OrderManagementServiceImpl()
    {
        Order order102, order103, order104, order105;
        order102.set_id("102");
        order102.add_items("Google Pixel 3A");
        order102.add_items("Mac Book Pro");
        order102.set_destination("Mountain View, CA");
        order102.set_price(1800.00);
        orderMap["102"] = order102;

        order103.set_id("103");
        order103.add_items("Apple Watch S4");
        order103.set_destination("San Jose, CA");
        order103.set_price(400.00);
        orderMap["103"] = order103;
                
        order104.set_id("104");
        order104.add_items("Google Home Mini");
        order104.add_items("Google Nest Hub");
        order104.set_destination("Mountain View, CA");
        order104.set_price(400.00);
        orderMap["104"] = order104;

        order105.set_id("105");
        order105.add_items("Amazon Echo");
        order105.set_destination("San Jose, CA");
        order105.set_price(30.00);
        orderMap["105"] = order105;
    }

    Status addOrder(ServerContext* context, const ecommerce::Order* request, StringValue* response) override 
    {
        std::cout<<"Order Added. ID : " << request->id() << std::endl;
        orderMap[request->id()] = *request;
        response->set_value(request->id());
        return Status::OK;
    }

    Status getOrder(ServerContext* context, const StringValue* request, ecommerce::Order* response) override 
    {
        auto it = orderMap.find(request->value());
        if (it != orderMap.end()) {
            std::cout<<"Found order with ID: " << request->value() << std::endl;
            *response = it->second;
        }
        else {
            std::cout<<"Order does not exist. : " << request->value() << std::endl;
        }
        return Status::OK;
    }

    Status searchOrders(ServerContext* context, const StringValue* request, grpc::ServerWriter<ecommerce::Order>* writer) override 
    {
        std::cout << "Search value: " << request->value() << std::endl;
        for (auto it = orderMap.begin(); it != orderMap.end(); ++it) 
        {
            const std::string& key = it->first;        // Accessing the key
            ecommerce::Order& value = it->second;      // Accessing the value

            for (const std::string& item : value.items()) 
            {
                if (item.find(request->value()) != std::string::npos) 
                {
                    std::cout << "Matching Order Found : " << key << std::endl;
                    writer->Write(value);
                    break;
                }
            }
        }
        return Status::OK;
    }

    Status updateOrders(ServerContext* context, grpc::ServerReader<ecommerce::Order>* reader, StringValue* response) override {
        Order receivedOrder;
        while (reader->Read(&receivedOrder)) {
            orderMap[receivedOrder.id()] = receivedOrder;
            std::cout << "Order ID : " << receivedOrder.id() << " - Updated" << std::endl;
        }
        return Status::OK;
    }

    Status processOrders(ServerContext* context, grpc::ServerReaderWriter< CombinedShipment, StringValue>* stream) override {
        int batchMarker = 1;
        const int orderBatchSize = 3; // Define your batch size

        StringValue orderID;
        while (stream->Read(&orderID)) 
        {
            std::string destination = orderMap[orderID.value()].destination();
            CombinedShipment shipment;
            auto it = combinedShipmentMap.find(destination);
            if (it != combinedShipmentMap.end()) {
                shipment = it->second;
                Order* ord = shipment.add_orderslist(); // Add a pointer to the order list
                *ord = orderMap[orderID.value()];
                combinedShipmentMap[destination] = shipment;

            } else {
                CombinedShipment comShip;
                comShip.set_id("cmb - " + destination);
                comShip.set_status("Processed!");
                Order* ord = comShip.add_orderslist(); // Add a pointer to the order list
                *ord = orderMap[orderID.value()];

                combinedShipmentMap[destination] = comShip;
                std::cout << comShip.orderslist_size() << " " << comShip.id() << std::endl;
            }

            if (batchMarker == orderBatchSize) {
                for (const auto& combined : combinedShipmentMap) {
                    if (!stream->Write(combined.second)) {
                        return Status(grpc::StatusCode::ABORTED, "Stream write failed");
                    }
                }
                batchMarker = 0;
                combinedShipmentMap.clear();
            } else {
                ++batchMarker;
            }
        }

        return Status::OK;
    }
private:
    std::unordered_map<std::string, ecommerce::Order> orderMap;
    std::map<std::string, CombinedShipment> combinedShipmentMap;
};

class OrderUnaryServerInterceptor : public Interceptor {
public:
    void Intercept(InterceptorBatchMethods* methods) override {
        
        methods->Proceed();
    }
};

// Define the interceptor for server streaming RPC.
class OrderServerStreamInterceptor : public Interceptor {
public:
    void Intercept(InterceptorBatchMethods* methods) override {
        if (methods->QueryInterceptionHookPoint(InterceptionHookPoints::POST_SEND_MESSAGE)) {
            // Pre-processing logic for sending a message
            auto currentTime = std::chrono::system_clock::now();
            std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);

            std::cout << "====== [Server Stream Interceptor Wrapper]: Send a message at "
                      << std::ctime(&currentTime_t) << std::endl;
        }
        else if (methods->QueryInterceptionHookPoint(InterceptionHookPoints::POST_RECV_MESSAGE)) {
            // Post-processing logic for receiving a message
            auto currentTime = std::chrono::system_clock::now();
            std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);

            std::cout << "====== [Server Stream Interceptor Wrapper]: Receive a message at "
                      << std::ctime(&currentTime_t) << std::endl;
        }
        methods->Proceed();
    }
};


class ServerInterceptorFactory : public ServerInterceptorFactoryInterface {
public:
    Interceptor* CreateServerInterceptor(ServerRpcInfo* info) override {
        if (static_cast<ServerRpcInfo::Type>(info->type()) == ServerRpcInfo::Type::UNARY)
        {
            std::cout << "+++++ [Server Interceptor] " << info->method() <<std::endl;
            return new OrderUnaryServerInterceptor();
        }
        else
        {
            std::cout << "===== [Server Stream Interceptor] " << info->method() <<std::endl;
            return new OrderServerStreamInterceptor();
        }
    }
};

void RunServer() 
{
    std::string server_address("0.0.0.0:50051");
    OrderManagementServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    // Register interceptor
    std::vector<std::unique_ptr<ServerInterceptorFactoryInterface>> interceptor;
    interceptor.push_back(std::unique_ptr<ServerInterceptorFactoryInterface>(
        new ServerInterceptorFactory()));
    builder.experimental().SetInterceptorCreators(std::move(interceptor));

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main() 
{
    RunServer();
    return 0;
}
