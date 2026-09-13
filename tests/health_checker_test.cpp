//
// Created by kuritayu on 2026/09/13.
//
#include <cassert>

#include "health_checker.h"
#include "../src/health_checker.h"

#include <iostream>

int main() {
    assert(checkTableHealth("users") == true);
    assert(checkTableHealth("orders") == false);
    assert(checkTableHealth("") == false);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
