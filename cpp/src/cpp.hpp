#pragma once

#include <string>

struct cpp {
    int i { 23 };
    double d { 3.14 };
    std::string hello { "hello" };
};

auto run() -> int;
