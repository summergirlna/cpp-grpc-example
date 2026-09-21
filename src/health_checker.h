//
// Created by kuritayu on 2026/09/13.
//
#pragma once

#include <string>

struct HealthCheckResult {
    bool healthy;
    std::string message;
};

HealthCheckResult checkTableHealth(const std::string& tableName);