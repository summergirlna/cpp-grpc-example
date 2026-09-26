cmake_minimum_required(VERSION 3.20)

project(cpp-grpc-example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#find_package(Protobuf CONFIG REQUIRED)
find_package(Protobuf REQUIRED)
#find_package(gRPC CONFIG REQUIRED)
find_package(gRPC REQUIRED)

enable_testing()

#set(PROTO_FILE proto/db_health.proto)

#protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILE})

# gRPC Server
add_executable(db_health_server
        src/server.cpp
        src/app/check_table_health_use_case.cpp
        src/infrastructure/mock_table_health_checker.cpp
        generated/db_health.pb.cc
        generated/db_health.grpc.pb.cc
)

target_include_directories(db_health_server PRIVATE
        src
        generated
)

target_link_libraries(db_health_server PRIVATE
        gRPC::grpc++
        protobuf::libprotobuf
)

add_executable(db_health_client
        src/client.cpp
        generated/db_health.pb.cc
        generated/db_health.grpc.pb.cc
)

target_include_directories(db_health_client PRIVATE
        generated
)

target_link_libraries(db_health_client PRIVATE
        gRPC::grpc++
        protobuf::libprotobuf
)

# CLI
add_executable(cpp-grpc-example
        src/main.cpp
        src/app/check_table_health_use_case.cpp
        src/infrastructure/mock_table_health_checker.cpp
)

target_include_directories(cpp-grpc-example PRIVATE
        src
)

# test
add_executable(health_checker_test
        tests/check_table_health_use_case_test.cpp
        src/app/check_table_health_use_case.cpp
        src/infrastructure/mock_table_health_checker.cpp
)

target_include_directories(health_checker_test PRIVATE
        src
)

add_executable(proto_message_test
        tests/proto_message_test.cpp
        generated/db_health.pb.cc
)

target_include_directories(proto_message_test PRIVATE
        generated
)

target_link_libraries(proto_message_test PRIVATE
        protobuf::libprotobuf
)

add_executable(grpc_generated_test
        tests/grpc_generated_test.cpp
        generated/db_health.pb.cc
        generated/db_health.grpc.pb.cc
)

target_include_directories(grpc_generated_test PRIVATE
        generated
)

target_link_libraries(grpc_generated_test PRIVATE
        gRPC::grpc++
        protobuf::libprotobuf
)

add_test(NAME health_checker_test COMMAND health_checker_test)
add_test(NAME proto_message_test COMMAND proto_message_test)
add_test(NAME grpc_generated_test COMMAND grpc_generated_test)