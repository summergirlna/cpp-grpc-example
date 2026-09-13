cmake_minimum_required(VERSION 3.20)

project(cpp-grpc-example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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