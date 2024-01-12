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

## Deadlines
Deadlines and timeouts are two commonly used patterns in distributed
computing. Deadlines can be used for specifying an exact point in time by which an operation must complete, while timeouts specify a maximum duration for which the client or server is willing to wait. 
- `Timeouts` allow you to specify how long a client application can wait
for an RPC to complete before it terminates with an error. A timeout is usually
specified as a duration and locally applied at each client side.
- A `deadline` is expressed in absolute time from the beginning of a request (even if
the API presents them as a duration offset) and applied across multiple service
invocations. The application that initiates the request sets the deadline and theentire request chain needs to respond by the deadline.