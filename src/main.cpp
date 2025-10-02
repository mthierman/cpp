#include <project.hpp>
#include <print>
#include <ranges>
#include <argz/argz.hpp>
#include <pane/pane.hpp>

auto print_version() -> void { std::println("0.0.0"); }

auto wmain(int /* argc */, wchar_t* /* argv[] */, wchar_t* /* envp */[]) -> int {
    auto args { pane::system::command_line_arguments() };

    auto argv = std::ranges::to<std::vector<const char*>>(
        args | std::views::transform([](const std::u8string& s) {
        return reinterpret_cast<const char*>(s.c_str());
    }));

    // argz::about about { reinterpret_cast<const char*>(PROJECT_DESCRIPTION.data()),
    //                     reinterpret_cast<const char*>(PROJECT_VERSION.data()) };
    std::string description { std::string("\x1b[32m")
                              + reinterpret_cast<const char*>(PROJECT_DESCRIPTION.data())
                              + "\x1b[0m" };

    std::string version { std::string("\x1b[32m")
                          + reinterpret_cast<const char*>(PROJECT_VERSION.data()) + "\x1b[0m" };

    argz::about about;
    about.description = description;
    about.version = version;

    std::string input {};
    std::string study {};
    int number = 123;
    bool boolean = true;
    std::optional<int> number_opt {};
    argz::options opts { { { "input", 'i' }, input, "the input file" },
                         { { "study", 's' }, study, "a study file" },
                         { { "number" }, number, "input an int" },
                         { { "boolean" }, boolean, "a boolean" },
                         { { "number_opt" }, number_opt, "input an int" } };

    try {
        argz::parse(about, opts, argv.size(), argv.data());
    } catch (const std::exception& e) {
        std::println("{}", e.what());
    }

    return 0;
}
