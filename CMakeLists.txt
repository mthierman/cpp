cmake_minimum_required(VERSION 3.31)
project(cv VERSION 0.0.0 DESCRIPTION "C++ package manager")
add_executable(cv)
target_sources(cv PRIVATE src/main.cpp src/app.cpp)
target_compile_features(cv PRIVATE c_std_17 cxx_std_23)
target_compile_definitions(cv PRIVATE UNICODE WIN32_LEAN_AND_MEAN NOMINMAX GDIPVER=0x0110)
target_compile_options(
    cv
    PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:
        /W4
        /WX
        /utf-8
        /bigobj
        /diagnostics:caret
        /permissive-
        /Zc:__cplusplus,enumTypes,templateScope,throwingNew,preprocessor
        >
        $<$<AND:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_FRONTEND_VARIANT:MSVC>>:
        /W4
        /WX
        -Wno-braced-scalar-init
        >
        $<$<AND:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_FRONTEND_VARIANT:GNU>>:
        -Wall
        -Werror
        -Wno-braced-scalar-init
        >
)
target_link_options(
    cv
    PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:
        /WX
        >
        $<$<AND:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_FRONTEND_VARIANT:MSVC>>:
        /WX
        >
        $<$<AND:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_FRONTEND_VARIANT:GNU>>:
        -Wl,/WX
        >
)
install(TARGETS cv RUNTIME DESTINATION .)
