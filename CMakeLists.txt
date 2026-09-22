cmake_minimum_required(VERSION 3.20)

project(cpp-grpc-example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Protobuf CONFIG REQUIRED)

enable_testing()

#set(PROTO_FILE proto/db_health.proto)

#protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILE})

add_executable(cpp-grpc-example
        src/main.cpp
        src/health_checker.cpp
)

target_include_directories(cpp-grpc-example PRIVATE
        src
)

add_executable(health_checker_test
        tests/health_checker_test.cpp
        src/health_checker.cpp
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

add_test(NAME health_checker_test COMMAND health_checker_test)
add_test(NAME proto_message_test COMMAND proto_message_test)