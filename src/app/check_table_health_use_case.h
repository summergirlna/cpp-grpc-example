//
// Created by kuritayu on 2026/09/23.
//
#pragma once

#include "domain/health_check_result.h"
#include "domain/table_health_checker.h"

namespace db_health::app {
class CheckTableHealthUseCase {
public:
    explicit CheckTableHealthUseCase(const domain::TableHealthChecker& tableHealthChecker);

    [[nodiscard]] domain::HealthCheckResult execute(const std::string& tableName) const;

private:
    const domain::TableHealthChecker* tableHealthChecker_;
};

}  // namespace db_health::app
