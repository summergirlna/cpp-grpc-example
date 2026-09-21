//
// Created by kuritayu on 2026/09/13.
//
#include <cassert>

#include "health_checker.h"

#include <iostream>

int main() {
    const HealthCheckResult usersResult = checkTableHealth("users");
    assert(usersResult.healthy == true);
    assert(usersResult.message == "table is readable");

    const HealthCheckResult ordersResult = checkTableHealth("orders");
    assert(ordersResult.healthy == false);
    assert(ordersResult.message == "table is not readable");

    const HealthCheckResult emptyResult = checkTableHealth("");
    assert(emptyResult.healthy == false);
    assert(emptyResult.message == "table name is empty");

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
