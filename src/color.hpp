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

inline constexpr const char8_t* get_color(color c) {
    switch (c) {
        case color::none:
            return u8"\x1b[0m";
        case color::black:
            return u8"\x1b[30m";
        case color::red:
            return u8"\x1b[31m";
        case color::green:
            return u8"\x1b[32m";
        case color::yellow:
            return u8"\x1b[33m";
        case color::blue:
            return u8"\x1b[34m";
        case color::magenta:
            return u8"\x1b[35m";
        case color::cyan:
            return u8"\x1b[36m";
        case color::white:
            return u8"\x1b[37m";
        case color::bright_black:
            return u8"\x1b[90m";
        case color::bright_red:
            return u8"\x1b[91m";
        case color::bright_green:
            return u8"\x1b[92m";
        case color::bright_yellow:
            return u8"\x1b[93m";
        case color::bright_blue:
            return u8"\x1b[94m";
        case color::bright_magenta:
            return u8"\x1b[95m";
        case color::bright_cyan:
            return u8"\x1b[96m";
        case color::bright_white:
            return u8"\x1b[97m";
        default:
            return u8"\x1b[0m";
    }
}

enum class style { none, bold, dim, italic, underline, inverse, hidden };

inline constexpr const char8_t* get_style(style s) {
    switch (s) {
        case style::none:
            return u8"\x1b[0m";
        case style::bold:
            return u8"\x1b[1m";
        case style::dim:
            return u8"\x1b[2m";
        case style::italic:
            return u8"\x1b[3m";
        case style::underline:
            return u8"\x1b[4m";
        case style::inverse:
            return u8"\x1b[7m";
        case style::hidden:
            return u8"\x1b[8m";
        default:
            return u8"\x1b[0m";
    }
}

template <color c = color::none, style... styles>
inline std::u8string paint(std::u8string_view text) {
    std::u8string result;
    ((result += get_style(styles)), ...);
    result += get_color(c);
    result += std::u8string { text } + get_style(style::none);

    return result;
}

template <style... styles> inline auto paint(std::u8string_view text) -> std::u8string {
    return paint<color::none, styles...>(text);
}
