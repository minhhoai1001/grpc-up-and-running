#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <string>
#include <unordered_map>
#include <random>
#include <iomanip>
#include <grpcpp/grpcpp.h>
#include "ecommerce/product_info.grpc.pb.h"

#include "base64.hpp"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::StatusCode;
using ecommerce::Product;
using ecommerce::ProductID;
using ecommerce::ProductInfo;

class ProductInfoService final : public ProductInfo::Service {
    Status addProduct(ServerContext* context, const Product* request, ProductID* response) override {
        
        if (!authencation(context)) {
            return Status(StatusCode::UNAUTHENTICATED, "Invalid password");
        }
        
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
        
        if (!authencation(context)) {
            return Status(StatusCode::UNAUTHENTICATED, "Invalid password");
        }
        
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

    std::string user = "user";
    std::string password = "password123";

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

    bool authencation(ServerContext* context)
    {
        const std::multimap<grpc::string_ref, grpc::string_ref>& metadata = context->client_metadata();
        auto it = metadata.find(user);
        std::string password_base64 = base64::to_base64(user+password);
        if (it == metadata.end() || it->second != password_base64) {
            return false;
        }
        else
        {
            return true;
        }
    }
};

std::string LoadFile(const std::string& file_path) {
    std::ifstream file(file_path);
    if (file) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    } else {
        // Handle error, e.g., file not found
        return "";
    }
}

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    ProductInfoService service;

    // Load server key and certificate
    std::string private_key = "../../certs/server.key";
    std::string certificate = "../../certs/server.crt";
    // grpc::SslServerCredentialsOptions::PemKeyCertPair key_cert_pair = {private_key, certificate};
    grpc::SslServerCredentialsOptions::PemKeyCertPair key_cert_pair;
    key_cert_pair.private_key = LoadFile(private_key);
    key_cert_pair.cert_chain = LoadFile(certificate);

    grpc::SslServerCredentialsOptions ssl_opts;
    ssl_opts.pem_key_cert_pairs.push_back(key_cert_pair);
    std::shared_ptr<grpc::ServerCredentials> creds = grpc::SslServerCredentials(ssl_opts);

    ServerBuilder builder;
    builder.AddListeningPort(server_address, creds);
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main() {
    RunServer();

    return 0;
}