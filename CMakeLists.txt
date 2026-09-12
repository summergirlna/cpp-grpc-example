cmake_minimum_required(VERSION 3.20)

project(cpp-grpc-example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp-grpc-example
        src/main.cpp
)
