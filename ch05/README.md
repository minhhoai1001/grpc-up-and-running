# Chapter 5. gRPC: Beyond the Basics

## Interceptors
As you build gRPC applications, you may want to execute some common logic
before or after the execution of the remote function, for either client or server
applications. In gRPC you can intercept that RPC’s execution to meet certain
requirements such as logging, authentication, metrics, etc., using an extension
mechanism called an *interceptor*. gRPC provides simple APIs to implement and
install interceptors in your client and server gRPC applications.

gRPC interceptors can be categorized into two types based on the type of RPC
calls they intercept. For unary RPC you can use `unary interceptors`, while for
streaming RPC you can use `streaming interceptors`. These interceptors can be
used on the gRPC server side or on the gRPC client side.

### Server-Side Interceptors
- **Unary Interceptors**: These interceptors are executed for unary RPCs on the server side.
- **Stream Interceptors**: These interceptors are executed for client-streaming and server-streaming RPCs on the server side.