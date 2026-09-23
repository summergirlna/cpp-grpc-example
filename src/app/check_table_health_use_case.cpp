//
// Created by kuritayu on 2026/09/23.
//

#include "check_table_health_use_case.h"

namespace db_health::app {
CheckTableHealthUseCase::CheckTableHealthUseCase(
    const domain::TableHealthChecker& tableHealthChecker)
    : tableHealthChecker_(&tableHealthChecker) {}

domain::HealthCheckResult CheckTableHealthUseCase::execute(const std::string& tableName) const {
    return tableHealthChecker_->check(tableName);
}
}  // namespace db_health::app