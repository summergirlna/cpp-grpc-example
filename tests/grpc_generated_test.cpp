//
// Created by kuritayu on 2026/09/22.
//

#include <memory>

#include "db_health.grpc.pb.h"

int main() {
    std::unique_ptr<db_health::DbHealthService::Stub> stub;

    std::cout << "gRPC generated code test passed" << '\n';

    return 0;
}
