cmake_minimum_required(VERSION 3.19)
project(productinfo)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads)

set(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")

set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)
if(CMAKE_CROSSCOMPILING)
    find_program(_PROTOBUF_PROTOC protoc)
else()
    set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
endif()

find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")

set(_GRPC_GRPCPP gRPC::grpc++)
if(CMAKE_CROSSCOMPILING)
    find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)
else()
    set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)
endif()

set(PROTO_NAME "product_info")
get_filename_component(proto "../proto/${PROTO_NAME}.proto" ABSOLUTE)
get_filename_component(proto_path "${proto}" PATH)

set(proto_sources "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce/${PROTO_NAME}.pb.cc")
set(proto_headers "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce/${PROTO_NAME}.pb.h")
set(grpc_sources "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce/${PROTO_NAME}.grpc.pb.cc")
set(grpc_headers "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce/${PROTO_NAME}.grpc.pb.h")
add_custom_command(
    OUTPUT "${proto_sources}" "${proto_headers}" "${grpc_sources}" "${grpc_headers}"
    COMMAND ${_PROTOBUF_PROTOC}
    ARGS --grpc_out "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce" --cpp_out "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce"
    -I "${proto_path}"
    --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
    "${proto}"
    DEPENDS "${proto}")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

add_library(grpc_proto
        ${proto_sources}
        ${proto_headers}
        ${grpc_sources}
        ${grpc_headers})
target_link_libraries(grpc_proto
        ${_PROTOBUF_LIBPROTOBUF}
        ${_REFLECTION}
        ${_GRPC_GRPCPP})

foreach(_target client server)
    add_executable(${_target} "${_target}.cpp")
    target_link_libraries(${_target}
            grpc_proto
            ${_PROTOBUF_LIBPROTOBUF}
            ${_REFLECTION}
            ${_GRPC_GRPCPP})
endforeach()