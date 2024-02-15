## ``ProductInfo`` Service and Client - Go Implementation

## Generate Go language code from the product_info.proto file
Go to folder server and client
```
protoc -I ../../proto/ --go_out=plugins=grpc:ecommerce ../../proto/product_info.proto
```
## Building and Running Server
In order to build, Go to Go module root directory location (`secure-channel/go/server`) and execute the following shell command,
```
go mod init productinfo/server
go mod tidy
```
```
go build -o server main.go
./server
```

## Building and Running Client
In order to build, Go to Go module root directory location (`secure-channel/go/client`) and execute the following shell command,
```
go mod init productinfo/client
go mod tidy
```
```
go build -o client main.go
./client
```
## Additional Information

### Update after changing the service definition

```shell script 
go get -u github.com/grpc-up-and-running/samples/ch02/productinfo/go/product_info
```

### Generate Server key and certificate

* Generate Using [OpenSSL](../certs/README.md)