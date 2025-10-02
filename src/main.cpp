#include <project.hpp>
#include <print>
#include <ranges>
#include <argz/argz.hpp>
#include <pane/pane.hpp>

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
    auto args { pane::system::command_line_arguments() };

    std::println("args.size(): {}", args.size());

    // if (args.size() < 2) {
    //     std::println("No command given");
    // }

    auto argv = std::ranges::to<std::vector<const char*>>(
        args | std::views::transform([](const std::u8string& s) {
        return reinterpret_cast<const char*>(s.c_str());
    }));

    argz::about about { reinterpret_cast<const char*>(PROJECT_DESCRIPTION.data()),
                        reinterpret_cast<const char*>(PROJECT_VERSION.data()) };

    std::optional<std::string> config { std::nullopt };

    argz::options opts { { { "config", 'c' }, config, "config file" } };

    // try {
    //     argz::parse(about, opts, argv.size(), argv.data());
    // } catch (const std::exception& e) {
    //     std::println("{}", e.what());
    // }

    if (argv.size() < 2) {
        return 0;
    }

    std::string_view command { argv.at(1) };

    if (command == "init") {
        init(about, opts, argv);
    } else if (command == "install") {
        install();
    } else {
        std::println("unknown command: {}", command);
        return 1;
    }

    return 0;
}
