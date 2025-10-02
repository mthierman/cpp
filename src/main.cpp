#include <project.hpp>
#include <print>
#include <ranges>
#include <argz/argz.hpp>
#include <pane/pane.hpp>

auto wmain(int /* argc */, wchar_t* /* argv[] */, wchar_t* /* envp */[]) -> int {
    auto args { pane::system::command_line_arguments() };

    auto argv = std::ranges::to<std::vector<const char*>>(
        args | std::views::transform([](const std::u8string& s) {
        return reinterpret_cast<const char*>(s.c_str());
    }));

    argz::about about { reinterpret_cast<const char*>(PROJECT_DESCRIPTION.data()),
                        reinterpret_cast<const char*>(PROJECT_VERSION.data()) };

    std::optional<std::string> config { std::nullopt };

    argz::options opts { { { "config", 'c' }, config, "config file" } };

    try {
        argz::parse(about, opts, argv.size(), argv.data());
    } catch (const std::exception& e) {
        std::println("{}", e.what());
    }

    if (config) {
        std::println("{}", *config);
    }

    return 0;
}
