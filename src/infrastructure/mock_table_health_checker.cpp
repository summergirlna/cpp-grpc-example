#include "mock_table_health_checker.h"
//
// Created by kuritayu on 2026/09/23.
//
namespace db_health::infrastructure {

domain::HealthCheckResult MockTableHealthChecker::check(const std::string& tableName) const {
    if (tableName.empty()) {
        return {.healthy = false, .message = "table name is empty"};
    }

    if (tableName == "users") {
        return {.healthy = true, .message = "table is readable"};
    }

    return {.healthy = false, .message = "table is not readable"};
}
}  // namespace db_health::infrastructure