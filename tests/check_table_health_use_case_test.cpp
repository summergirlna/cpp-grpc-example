//
// Created by kuritayu on 2026/09/13.
//
#include "app/check_table_health_use_case.h"

#include <cassert>
#include <iostream>

#include "infrastructure/mock_table_health_checker.h"

int main() {
    db_health::infrastructure::MockTableHealthChecker tableHealthChecker;
    const db_health::app::CheckTableHealthUseCase useCase(tableHealthChecker);

    const db_health::domain::HealthCheckResult usersResult = useCase.execute("users");
    assert(usersResult.healthy);
    assert(usersResult.message == "table is readable");

    const db_health::domain::HealthCheckResult ordersResult = useCase.execute("orders");
    assert(!ordersResult.healthy);
    assert(ordersResult.message == "table is not readable");

    const db_health::domain::HealthCheckResult emptyResult = useCase.execute("");
    assert(!emptyResult.healthy);
    assert(emptyResult.message == "table name is empty");

    std::cout << "All tests passed!\n";

    return 0;
}
