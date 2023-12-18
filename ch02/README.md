# Chapter 2: Getting Started with gRPC
## ProductInfo Service and Client
- Online retail scenario has a  `ProductInfo` microservice which is responsible for managing the products and their information. The consumer of that service can add, retrieve products via that service.

- `ProductInfo` service and the consumer of that service are implemented in both `Go` and `C++` languages.

- This use case shows how you can implement both `ProductInfo` service and its consumer.

## Service Definition
```
package ecommerce;

service ProductInfo {
    rpc addProduct(Product) returns (ProductID);
    rpc getProduct(ProductID) returns (Product);
}

message Product {
    string id = 1;
    string name = 2;
    string description = 3;
    float price = 4;
}

message ProductID {
    string value = 1;
}
```

## Implementation
- [Go](./ch02/productinfo/go/README.md)
- [C++](./ch02/productinfo/cpp/README.md)