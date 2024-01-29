#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <string>
#include <grpcpp/grpcpp.h>
#include "ecommerce/product_info.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using ecommerce::Product;
using ecommerce::ProductID;
using ecommerce::ProductInfo;

class ProductInfoClient {
public:
    ProductInfoClient(std::shared_ptr<Channel> channel)
        : stub_(ProductInfo::NewStub(channel)) {}

    std::string AddProduct(const Product& product) {
        ProductID productID;
        ClientContext context;
        Status status = stub_->addProduct(&context, product, &productID);
        if (status.ok()) {
            return productID.value();
        } else {
            std::cout << "Error: " << status.error_code() << ": " << status.error_message() << std::endl;
            return "";
        }
    }

    Product GetProduct(const std::string& id) {
        ProductID productID;
        productID.set_value(id);
        Product product;
        ClientContext context;
        Status status = stub_->getProduct(&context, productID, &product);
        if (status.ok()) {
            return product;
        } else {
            std::cout << "Error: " << status.error_code() << ": " << status.error_message() << std::endl;
            return Product(); // Return an empty product on failure
        }
    }

private:
    std::unique_ptr<ProductInfo::Stub> stub_;
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

int main()
{
    // Create a client
    grpc::SslCredentialsOptions ssl_opts;
    ssl_opts.pem_root_certs = LoadFile("../../certs/server.crt");
    std::shared_ptr<grpc::ChannelCredentials> creds = grpc::SslCredentials(ssl_opts);
    ProductInfoClient client(grpc::CreateChannel("localhost:50051", creds));

    // Example usage: Add a product and then retrieve it
    Product newProduct;
    newProduct.set_name("Edifier-W7000NB");
    newProduct.set_description("Bluetooth headphone with noise canceling.");

    std::string addedProductID = client.AddProduct(newProduct);
    if (!addedProductID.empty()) 
    {
        std::cout << "Product ID: " << addedProductID << " added successfully \n";
    }

    Product retrievedProduct = client.GetProduct(addedProductID);
    if (retrievedProduct.id().empty())
    {
        std::cout << "Could not get product \n";
        return -1;
    }
    std::cout << "Retrieved Product: " << std::endl;
    std::cout << "ID: " << retrievedProduct.id() << std::endl;
    std::cout << "Name: " << retrievedProduct.name() << std::endl;
    std::cout << "Description: " << retrievedProduct.description() << std::endl;

    return 0;
}