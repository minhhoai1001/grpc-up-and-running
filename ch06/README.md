# Chapter 6. Secured gRPC

## Authenticating a gRPC Channel with TLS
`Transport Level Security (TLS)` aims to provide privacy and data integrity
between two communicating applications. Here, it's about providing a secure
connection between gRPC client and server applications. According to the
Transport Level Security Protocol Specification, when the connection between a
client and a server is secure, it should have one or more of the following
properties:
- **The connection is private**: Symmetric cryptography is used for data encryption. It is a type of encryption where only one key (a secret key) is used to both encrypt and
decrypt. These keys are generated uniquely for each connection based on a
shared secret that was negotiated at the start of the session.
- **The connection is reliable**: This occurs because each message includes a message integrity check to prevent undetected loss or alteration of the data during transmission.

### Enabling a One-Way Secured Connection
In a one-way connection, only the client validates the server to ensure that it
receives data from the intended server. When establishing the connection
between the client and the server, the server shares its public certificate with the
client, who then validates the received certificate. This is done through a
**certificate authority (CA)**, for CA-signed certificates. Once the certificate is
validated, the client sends the data encrypted using the secret key.

### Enabling an mTLS Secured Connection
The main intent of an mTLS connection between client and server is to have
control of clients who connect to the server. Unlike a one-way TLS connection,
the server is configured to accept connections from a limited group of verified
clients. Here both parties share their public certificates with each other and
validate the other party. The basic flow of connection is as follows:
1. Client sends a request to access protected information from the server.
2. The server sends its X.509 certificate to the client.
3. Client validates the received certificate through a CA for CA-signed
certificates.
4. If the verification is successful, the client sends its certificate to the
server.
5. Server also verifies the client certificate through the CA.
6. Once it is successful, the server gives permission to access protected
data.

## Authenticating gRPC Calls
In order to facilitate verification of the caller, gRPC provides the capability for
the client to inject his or her credentials (like username and password) on every
call. The gRPC server has the ability to intercept a request from the client and
check these credentials for every incoming call.

### Using Basic Authentication
**Basic authentication** is the simplest authentication mechanism. In this
mechanism, the client sends requests with the Authorization header with a
value that starts with the word Basic followed by a space and a base64-encoded
string `username:password`. For example, if the username is `admin` and the
password is `admin`, the header value looks like this:
```
Authorization: Basic YWRtaW46YWRtaW4=
```

### Using OAuth 2.0
OAuth 2.0 is a framework for access delegation. It allows users to grant limited
access to services on their behalf, rather than giving them total access like with a
username and password. Here we are not going to discuss OAuth 2.0 in detail. It
is helpful if you have some basic knowledge about how OAuth 2.0 works to
enable it in your application.

### Using JWT
JWT defines a container to transport identity information between the client and
server. A signed JWT can be used as a self-contained access token, which means
the resource server doesn't need to talk to the authentication server to validate
the client token. It can validate the token by validating the signature. The client
requests access from the authentication server, which verifies the client's
credentials, creates a JWT, and sends it to the client. The client application with
JWT allows access to resources.

### Using Google Token-Based Authentication
Identifying the users and deciding whether to let them use the services deployed
on the Google Cloud Platform is controlled by the Extensible Service Proxy
(ESP). ESP supports multiple authentication methods, including Firebase, Auth0,
and Google ID tokens. In each case, the client needs to provide a valid JWT in
their requests. In order to generate authenticating JWTs, we must create a service
account for each deployed service.