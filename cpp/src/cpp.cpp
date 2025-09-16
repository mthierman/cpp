#include "cpp.hpp"
#include <print>
#include <pane/pane.hpp>

auto run() -> void {
    cpp cpp;

    std::u8string buffer;

    if (auto ec { glz::write_json(cpp, buffer) }; !ec) {
        std::println("{}", buffer);
    }
}
