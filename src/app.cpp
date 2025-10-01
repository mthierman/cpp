#include "app.hpp"
#include <print>
#include <pane/pane.hpp>

auto cpp::print() -> void {
    std::u8string buffer;

    if (auto ec { glz::write_json(this, buffer) }; !ec) {
        std::println("{}", buffer);
    }
}

auto app() -> int {
    cpp cpp;

    cpp.print();

    return 0;
}
