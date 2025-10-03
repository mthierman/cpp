#include "color.hpp"
#include <project.hpp>
#include <print>
#include <pane/pane.hpp>

auto wmain() -> int {
    auto argv { pane::system::command_line_arguments() };
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
