#include "app.hpp"
#include <CLI/CLI.hpp>

auto wmain(int argc, wchar_t* argv[], wchar_t* /* envp */[]) -> int {
    CLI::App app { "App description" };

    std::string filename = "default";
    app.add_option("-f,--file", filename, "A help string");

    // CLI11_PARSE(app, argc, argv);
    try {
        (app).parse(argc, argv);
    } catch (const CLI::ParseError& e) {
        return (app).exit(e);
    }
    return 0;
}
