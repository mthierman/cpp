#include <string>
#include <CLI/CLI.hpp>

auto wmain(int argc, wchar_t* argv[], wchar_t* /* envp */[]) -> int {
    CLI::App app { "App description" };
    app.set_version_flag("--version", std::string(CLI11_VERSION));

    std::string filename = "default";
    app.add_option("-f,--file", filename, "A help string");

    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError& e) {
        return app.exit(e);
    }

    return 0;
}
