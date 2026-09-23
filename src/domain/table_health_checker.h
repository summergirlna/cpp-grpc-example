//
// Created by kuritayu on 2026/09/23.
//
#pragma once
#include "health_check_result.h"

namespace db_health::domain {

class TableHealthChecker {
public:
    TableHealthChecker() = default;
    virtual ~TableHealthChecker() = default;

    TableHealthChecker(const TableHealthChecker&) = delete;
    TableHealthChecker& operator=(const TableHealthChecker&) = delete;
    TableHealthChecker(TableHealthChecker&&) = delete;
    TableHealthChecker& operator=(TableHealthChecker&&) = delete;

    [[nodiscard]] virtual HealthCheckResult check(const std::string& tableName) const = 0;
};

}  // namespace db_health::domain
