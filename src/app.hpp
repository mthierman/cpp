#pragma once

#include <string>

struct cpp {
    int i { 23 };
    double d { 3.14 };
    std::string hello { "hello" };
    std::string test { "test" };

    auto print() -> void;
};

auto app() -> int;
