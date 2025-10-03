#include "color.hpp"
#include <project.hpp>
#include <print>
#include <pane/pane.hpp>

// https://clig.dev/

using namespace std::string_view_literals;

auto wmain(int /* argc */, wchar_t* /* argv[] */, wchar_t* /* envp */[]) -> int {
    auto argv { pane::system::command_line_arguments() };
    std::println("argv.size(): {}", argv.size());

    if (argv.size() == 1) {
        std::println("{}", PROJECT_DESCRIPTION);
        std::println();
        std::print("{}", paint<color::bright_blue, style::bold>(u8"Usage: "));
        std::println("{}", paint<color::bright_cyan>(u8"cv.exe [OPTIONS] <COMMAND>"));
        std::println();
    }

    return 0;
}
