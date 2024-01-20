cmake_minimum_required(VERSION 3.19)
project(order-service)

set(CMAKE_CXX_STANDARD 14)

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

get_filename_component(order_proto "../proto/order_management.proto" ABSOLUTE)
get_filename_component(order_proto_path "${order_proto}" PATH)
get_filename_component(hw_proto "../proto/helloworld.proto" ABSOLUTE)
get_filename_component(hw_proto_path "${hw_proto}" PATH)

set(order_proto_src "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce/order_management.pb.cc")
set(order_proto_h "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce/order_management.pb.h")
set(order_grpc_src "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce/order_management.grpc.pb.cc")
set(order_grpc_h "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce/order_management.grpc.pb.h")

set(hw_proto_src "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce/helloworld.pb.cc")
set(hw_proto_h "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce/helloworld.pb.h")
set(hw_grpc_src "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce/helloworld.grpc.pb.cc")
set(hw_grpc_h "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce/helloworld.grpc.pb.h")

add_custom_command(
        OUTPUT "${order_proto_src}" "${order_proto_h}" "${order_grpc_src}" "${order_grpc_h}"
            "${hw_proto_src}" "${hw_proto_h}" "${hw_grpc_src}" "${hw_grpc_h}"
        COMMAND ${_PROTOBUF_PROTOC}
        ARGS --grpc_out "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce" --cpp_out "${CMAKE_CURRENT_SOURCE_DIR}/ecommerce"
        -I "${order_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${order_proto}" "${hw_proto}"
        DEPENDS "${order_proto}" "${hw_proto}")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

add_library(grpc_proto
        ${order_proto_src}
        ${order_proto_h}
        ${order_grpc_src}
        ${order_grpc_h}
        ${hw_proto_src}
        ${hw_proto_h}
        ${hw_grpc_src}
        ${hw_grpc_h})

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