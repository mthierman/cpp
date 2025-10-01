// #include "app.hpp"
#include <argz/argz.hpp>

// auto wmain(int /* argc */, wchar_t* /* argv */[], wchar_t* /* envp */[]) -> int { return app(); }

auto wmain(int argc, wchar_t* argv[], wchar_t* /* envp */[]) -> int {
    constexpr std::string_view version = "1.2.3";
    argz::about about { "My program description", version };

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
        argz::parse(about, opts, argc, (char**)nullptr);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
