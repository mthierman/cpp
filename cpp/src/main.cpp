#include <print>
#include <string>
#include <pane/pane.hpp>

struct my_struct {
    int i { 23 };
    double d { 3.14 };
    std::string hello { "hello" };
};

auto wmain(int /* argc */, wchar_t* /* argv */[], wchar_t* /* envp */[]) -> int {
    my_struct my_struct;

    std::u8string buffer;

    if (auto ec { glz::write_json(my_struct, buffer) }; !ec) {
        std::println("{}", buffer);
    }

    return 0;
}
