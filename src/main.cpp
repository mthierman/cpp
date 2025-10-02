#include "color.hpp"
#include <project.hpp>
#include <print>
// #include <ranges>
#include <argz/argz.hpp>
#include <pane/pane.hpp>

struct command {
    std::string_view cmd;
    argz::options opts;
};

auto help(const argz::about& about, const argz::options& opts) -> void {
    std::string indent { "        " };

    std::println();
    std::print("{}", paint<color::bright_blue, style::bold>("Usage: "));
    std::println("{}", paint<color::bright_cyan>("cv.exe [OPTIONS]"));
    std::println();

    std::println(
        "{}{}{}", paint<color::bright_cyan>("-h"), ", ", paint<color::bright_cyan>("--help"));
    std::println("{}{}", indent, "print help");

    std::println(
        "{}{}{}", paint<color::bright_cyan>("-v"), ", ", paint<color::bright_cyan>("--version"));
    std::println("{}{}", indent, "print version and exit");

    for (auto& [ids, v, h] : opts) {
        if (ids.alias != '\0') {
            std::println("{}{}{}{}{}",
                         paint<color::bright_cyan>("-"),
                         paint<color::bright_cyan>(std::string_view(&ids.alias, 1)),
                         ", ",
                         paint<color::bright_cyan>("--"),
                         paint<color::bright_cyan>(ids.id));
        } else {
            std::println("{}{}", ids.id.size() == 1 ? "-" : "--", ids.id);
        }

        std::print("{}{}{}{}",
                   indent,
                   h,
                   argz::detail::to_string(v).empty() ? "\n" : ", default: ",
                   argz::detail::to_string(v));
    }
}

auto init(argz::about& about, argz::options& opts, std::vector<const char*>& argv) -> void {
    std::println("command is init");

    try {
        argz::parse(about, opts, argv.size() - 1, argv.data() + 1);
    } catch (const std::exception& e) {
        std::println("{}", e.what());
    }
}

auto install() -> void { std::println("command is install"); }

auto wmain(int /* argc */, wchar_t* /* argv[] */, wchar_t* /* envp */[]) -> int {
    // argz::about about { reinterpret_cast<const char*>(PROJECT_DESCRIPTION.data()),
    //                     reinterpret_cast<const char*>(PROJECT_VERSION.data()) };

    std::optional<std::string> config { std::nullopt };
    argz::options opts { { { "config", 'c' }, config, "config file" } };

    auto args { pane::system::command_line_arguments() };

    // auto argv = std::ranges::to<std::vector<const char*>>(
    //     args | std::views::transform([](const std::u8string& s) {
    //     return reinterpret_cast<const char*>(s.c_str());
    // }));

    if (args.size() == 1) {
        std::println("{}", PROJECT_DESCRIPTION);
        // help(about, opts);
    }

    std::println("args.size(): {}", args.size());

    // try {
    //     argz::parse(about, opts, argv.size(), argv.data());
    // } catch (const std::exception& e) {
    //     std::println("{}", e.what());
    // }

    // if (argv.size() < 2) {
    //     return 0;
    // }

    // std::string_view command { argv.at(1) };

    // if (command == "init") {
    //     init(about, opts, argv);
    // } else if (command == "install") {
    //     install();
    // } else {
    //     std::println("unknown command: {}", command);
    //     return 1;
    // }

    return 0;
}
