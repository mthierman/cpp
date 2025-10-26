#include "app.hpp"
#include "color.hpp"
#include <project.hpp>
#include <pane/pane.hpp>
#include <print>

namespace app {
auto run() -> int {
    auto argv { pane::system::get_argv_u8() };
    std::println("{}", u8"https://clig.dev/");

    for (auto [idx, arg] : std::views::enumerate(argv) | std::views::as_const) {
        std::println("{}/{}: {}", idx, argv.size(), arg);
    }

    std::println();

    if (argv.size() == 1) {
        std::println("{}", PROJECT_DESCRIPTION);
        std::println();
        std::print("{}", paint<color::bright_blue, style::bold>(u8"Usage: "));
        std::println("{}", paint<color::bright_cyan>(u8"cv.exe [OPTIONS] <COMMAND>"));
        std::println();
    }

    return 0;
}
} // namespace app

// auto cpp::print() -> void {
//     std::u8string buffer;

//     if (auto ec { glz::write_json(this, buffer) }; !ec) {
//         std::println("{}", buffer);
//     }
// }

// auto app() -> int {
//     cpp cpp;

//     cpp.print();

//     return 0;
// }
