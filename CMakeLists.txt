cmake_minimum_required(VERSION 3.31)
project(cpp)
include(FetchContent)

FetchContent_Declare(
    pane
    GIT_REPOSITORY "https://github.com/mthierman/pane.git"
    GIT_TAG "main"
)
FetchContent_MakeAvailable(pane)

FetchContent_Declare(
    cli11
    GIT_REPOSITORY "https://github.com/CLIUtils/CLI11.git"
    GIT_TAG "v2.5.0"
)
FetchContent_MakeAvailable(cli11)

add_executable(cpp)
target_sources(cpp PRIVATE "src/main.cpp" "src/app.cpp")
target_link_libraries(cpp PRIVATE pane::pane CLI11::CLI11)
