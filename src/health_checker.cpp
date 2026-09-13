//
// Created by kuritayu on 2026/09/13.
//

#include "health_checker.h"

bool checkTableHealth(const std::string& tableName) {
    if (tableName.empty()) {
        return false;
    }

    // todo テーブル名固定なのは修正する
    return tableName == "users";
}