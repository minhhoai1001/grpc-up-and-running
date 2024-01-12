## ``OrderManagement`` Service and Client - Go Implementation

### Generate Go language code from the order_management.proto file. Do for both server and client
```
protoc -I ../../proto/ --go_out=plugins=grpc:ecommerce ../../proto/order_management.proto
```

### Building and Running Service
In order to build, Go to Go module root directory location (`order-service/go/server`) and execute the following shell command,

```
go mod init ordermgt/service
go build -o server main.go
```

```
./server
```

### Building and Running Client
In order to build, Go to Go module root directory location (`order-service/go/client`) and execute the following shell command,

```
go mod init ordermgt/client
go build -o client main.go
```