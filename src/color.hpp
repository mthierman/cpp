#pragma once
#include <string>
#include <string_view>

enum class color {
    none,
    black,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white,
    bright_black,
    bright_red,
    bright_green,
    bright_yellow,
    bright_blue,
    bright_magenta,
    bright_cyan,
    bright_white
};

inline constexpr const char* get_color(color c) {
    switch (c) {
        case color::none:
            return "\x1b[0m";
        case color::black:
            return "\x1b[30m";
        case color::red:
            return "\x1b[31m";
        case color::green:
            return "\x1b[32m";
        case color::yellow:
            return "\x1b[33m";
        case color::blue:
            return "\x1b[34m";
        case color::magenta:
            return "\x1b[35m";
        case color::cyan:
            return "\x1b[36m";
        case color::white:
            return "\x1b[37m";
        case color::bright_black:
            return "\x1b[90m";
        case color::bright_red:
            return "\x1b[91m";
        case color::bright_green:
            return "\x1b[92m";
        case color::bright_yellow:
            return "\x1b[93m";
        case color::bright_blue:
            return "\x1b[94m";
        case color::bright_magenta:
            return "\x1b[95m";
        case color::bright_cyan:
            return "\x1b[96m";
        case color::bright_white:
            return "\x1b[97m";
    }
}

enum class style { none, bold, dim, italic, underline, inverse, hidden };

inline constexpr const char* get_style(style s) {
    switch (s) {
        case style::none:
            return "\x1b[0m";
        case style::bold:
            return "\x1b[1m";
        case style::dim:
            return "\x1b[2m";
        case style::italic:
            return "\x1b[3m";
        case style::underline:
            return "\x1b[4m";
        case style::inverse:
            return "\x1b[7m";
        case style::hidden:
            return "\x1b[8m";
    }
}

template <color c = color::none, style... styles> inline std::string paint(std::string_view text) {
    std::string result;
    ((result += get_style(styles)), ...);
    result += get_color(c);
    result += std::string { text } + get_style(style::none);

    return result;
}

template <style... styles> inline auto paint(std::string_view text) -> std::string {
    return paint<color::none, styles...>(text);
}
