cmake_minimum_required(VERSION 3.31)

project(cv VERSION 0.0.0 DESCRIPTION "C++ package manager")

configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/src/project.hpp.in
    ${CMAKE_CURRENT_BINARY_DIR}/generated/project.hpp
    @ONLY
)

include(GNUInstallDirs)
include(FetchContent)

FetchContent_Declare(pane GIT_REPOSITORY https://github.com/mthierman/pane.git GIT_TAG main)

FetchContent_MakeAvailable(pane)

FetchContent_Declare(cli11 GIT_REPOSITORY "https://github.com/CLIUtils/CLI11.git" GIT_TAG "v2.5.0")

FetchContent_MakeAvailable(cli11)

add_executable(cv)

target_sources(
    cv
    PRIVATE src/main.cpp src/app.cpp
    PRIVATE FILE_SET HEADERS BASE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/generated
)

# target_include_directories(cv PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/generated)

target_link_libraries(cv PRIVATE pane::pane CLI11::CLI11)

install(TARGETS cv RUNTIME DESTINATION .)
