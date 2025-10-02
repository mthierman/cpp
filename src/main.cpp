// #include "app.hpp"
#include <argz/argz.hpp>
#include <pane/pane.hpp>
#include <ranges>
#include <version.hpp>

// auto wmain(int /* argc */, wchar_t* /* argv */[], wchar_t* /* envp */[]) -> int { return app(); }

auto wmain(int /* argc */, wchar_t* /* argv[] */, wchar_t* /* envp */[]) -> int {
    auto args { pane::system::command_line_arguments() };

    // First method:
    //
    // std::vector<const char*> argv_ptrs;
    // argv_ptrs.reserve(argc);

    // for (auto& s : args) {
    //     argv_ptrs.push_back(reinterpret_cast<const char*>(s.c_str()));
    // }

    // Second method:
    auto argv_ptrs = std::ranges::to<std::vector<const char*>>(
        args | std::views::transform([](const std::u8string& s) {
        return reinterpret_cast<const char*>(s.c_str());
    }));

    // constexpr std::string_view version = "1.2.3";
    argz::about about { "My program description",
                        reinterpret_cast<const char*>(PROJECT_VERSION.data()) };

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
        argz::parse(about, opts, argv_ptrs.size(), argv_ptrs.data());
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
