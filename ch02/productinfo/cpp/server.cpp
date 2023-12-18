#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <random>
#include <iomanip>
#include <grpcpp/grpcpp.h>
#include "ecommerce/product_info.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using ecommerce::Product;
using ecommerce::ProductID;
using ecommerce::ProductInfo;

class ProductInfoService final : public ProductInfo::Service {
    Status addProduct(ServerContext* context, const Product* request, ProductID* response) override {
        std::string uuid = generateUUIDv4();
        Product p;
        p.set_id(uuid);
        p.set_name(request->name());
        p.set_description(request->description());
        productMap[uuid] = p;
        response->set_value(uuid);
        std::cout << "Product: " << p.id() << ": " << p.name()<< " - Added \n";
        return Status::OK;
    }

    Status getProduct(ServerContext* context, const ProductID* request, Product* response) override {
        // Logic to fetch the product details using the ID from request
        auto it = productMap.find(request->value());
        if (it != productMap.end()) {
            std::cout << "Product " << it->second.id() << ": " << it->second.name() << " - Retrieved. \n";
            response->set_id(it->second.id());
            response->set_name(it->second.name());
            response->set_description(it->second.description());
        }
        return Status::OK;
    }
private:
    std::unordered_map<std::string, Product> productMap;

    std::string generateUUIDv4()
    {
        // Define a random device and a random number generator
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 15);

        const char* hexChars = "0123456789abcdef";

        std::string uuid = "xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx";
        for (char& c : uuid) {
            if (c == 'x') {
                int randomValue = dis(gen);
                c = hexChars[randomValue];
            } else if (c == 'y') {
                int randomValue = dis(gen) & 0x3 | 0x8;
                c = hexChars[randomValue];
            }
        }

        return uuid;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    ProductInfoService service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main() {
    RunServer();
    return 0;
}
