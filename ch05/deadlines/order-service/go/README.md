## ``OrderManagement`` Service and Client - Go Implementation

## ProductInfo Service and Client - Go Implementation

### Generate Go language code from the product_info.proto file
```
protoc -I ../../proto/ --go_out=plugins=grpc:ecommerce ../../proto/order_management.proto
```
### Building and Running Service
In order to build, Go to Go module root directory location (`order-service/go/server`) and execute the following shell command,

```
go build -o server main.go
```


```
./server
```

### Building and Running Client
In order to build, Go to Go module root directory location (`order-service/go/client`) and execute the following shell command,

```
go build -o client main.go
```


```
./client
# Add order
> add-order
# Get Order
> get-order
# Search Order: Server streaming scenario
> search
# Update Orders: Client streaming scenario
> update
# Process Order : Bi-di streaming scenario
> process
```