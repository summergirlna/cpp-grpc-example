//
// Created by kuritayu on 2026/09/13.
//
#include "health_checker.h"

#include <cassert>
#include <iostream>

int main() {
    const db_health::HealthCheckResult usersResult = db_health::checkTableHealth("users");
    assert(usersResult.healthy);
    assert(usersResult.message == "table is readable");

    const db_health::HealthCheckResult ordersResult = db_health::checkTableHealth("orders");
    assert(!ordersResult.healthy);
    assert(ordersResult.message == "table is not readable");

    const db_health::HealthCheckResult emptyResult = db_health::checkTableHealth("");
    assert(!emptyResult.healthy);
    assert(emptyResult.message == "table name is empty");

    std::cout << "All tests passed!" << '\n';

    return 0;
}
