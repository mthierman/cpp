cmake_minimum_required(VERSION 3.31)

project(cv VERSION 0.0.0)

configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/src/version.hpp.in
    ${CMAKE_CURRENT_BINARY_DIR}/generated/version.hpp
    @ONLY
)

include(GNUInstallDirs)
include(FetchContent)

FetchContent_Declare(pane GIT_REPOSITORY https://github.com/mthierman/pane.git GIT_TAG main)

FetchContent_MakeAvailable(pane)

add_executable(cv)

target_sources(cv PRIVATE src/main.cpp src/app.cpp)

target_include_directories(cv PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/generated)

target_link_libraries(cv PRIVATE pane::pane)

install(TARGETS cv RUNTIME DESTINATION .)
