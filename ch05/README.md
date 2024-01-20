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

## Cancellation
In a gRPC connection between a client and server application, both the client
and server make independent and local determinations of the success of the call.
For instance, you could have an RPC that finishes successfully on the server side
but fails on the client side. Similarly, there can be various conditions where the
client and server may end up with different conclusions on the results of an RPC.
When either the client or server application wants to terminate the RPC this can
be done by `canceling` the RPC. Once the RPC is canceled, no further RPC-
related messaging can be done and the fact that one party has canceled the RPC
is propagated to the other side.

## Error Handling
When we invoke a gRPC call, the client receives a response with a successful
status or an error with the corresponding error status. The client application
needs to be written in such a way that you handle all the potential errors and
error conditions. The server application requires you to handle errors as well as
generate the appropriate errors with corresponding status codes.

When an error occurs, gRPC returns one of its error-status codes with an
optional error message that provides more details of the error condition. The
status object is composed of an integer code and a string message that are
common to all gRPC implementations for different languages.

gRPC uses a set of well-defined gRPC-specific status codes. This includes status
codes such as the following:
| Code                 | Number | Description                                              |
|----------------------|--------|----------------------------------------------------------|
| OK                   | 0      | Success status.                                         |
| CANCELLED            | 1      | The operation was canceled (by the caller).              |
| UNKNOWN              | 2      | Unknown error.                                          |
| INVALID_ARGUMENT     | 3      | The client specified an invalid argument.                |
| DEADLINE_EXCEEDED    | 4      | The deadline expired before the operation could complete.|
| NOT_FOUND            | 5      | Some requested entity was not found.                     |
| ALREADY_EXISTS       | 6      | The entity that a client attempted to create already exists.|
| PERMISSION_DENIED    | 7      | The caller does not have permission to execute the specified operation.|
| RESOURCE_EXHAUSTED   | 8      | Some resource has been exhausted.                         |
| FAILED_PRECONDITION  | 9      | The operation was rejected because the system is not in a state required for the operation's execution.|
| ABORTED              | 10     | The operation was aborted.                                |
| OUT_OF_RANGE         | 11     | The operation was attempted past the valid range.        |
| UNIMPLEMENTED        | 12     | The operation is not implemented or is not supported/enabled in this service.|
| INTERNAL             | 13     | Internal errors.                                        |
| UNAVAILABLE          | 14     | The service is currently unavailable.                   |
| DATA_LOSS            | 15     | Unrecoverable data loss or corruption.                   |
| UNAUTHENTICATED      | 16     | The request does not have valid authentication credentials for the operation.|

## Multiplexing
In terms of gRPC services and client applications, we've seen so far a given
gRPC server with a gRPC service registered on it and a gRPC client connection
being used by a single client stub only. However, gRPC allows you to run
multiple gRPC services on the same gRPC server, as well as use
the same gRPC client connection for multiple gRPC client stubs. This capability
is known as `multiplexing`.

## Metadata
gRPC applications usually share information via RPC calls between gRPCservices and consumers. In most cases, information directly related to the
service's business logic and consumer is part of the remote method invocation
arguments. However, in certain conditions, you may want to share information
about the RPC calls that are not related to the business context of the RPC, so
they shouldn't be part of the RPC arguments. In such cases, you can use gRPC
metadata that you can send or receive from either the gRPC service or the gRPC
client.

