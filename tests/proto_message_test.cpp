#include <cassert>
#include <iostream>
#include <string>

#include "db_health.pb.h"

int main() {
    db_health::CheckTableHealthRequest request;
    request.set_table_name("users");

    assert(request.table_name() == "users");

    db_health::CheckTableHealthResponse response;
    response.set_healthy(true);
    response.set_message("table is readable");

    assert(response.healthy() == true);
    assert(response.message() == "table is readable");

    std::cout << "Protobuf message test passed!" << '\n';

    return 0;
}