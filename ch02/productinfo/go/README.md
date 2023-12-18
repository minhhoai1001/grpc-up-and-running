## ProductInfo Service and Client - Go Implementation

### Generate Go language code from the product_info.proto file
```
protoc -I ../../proto/ --go_out=plugins=grpc:ecommerce ../../proto/product_info.proto
```
### Building and Running Service
In order to build, Go to Go module root directory location (`productinfo/go/server`) and execute the following shell command,

```
go build -o server main.go
```


```
./server
```

### Building and Running Client
In order to build, Go to Go module root directory location (`productinfo/go/client`) and execute the following shell command,

```
go build -o client main.go
```


```
./client
```