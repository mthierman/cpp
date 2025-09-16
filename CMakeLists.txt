cmake_minimum_required(VERSION 4.0)
project(cpp)

include(FetchContent)
FetchContent_Declare(
    pane
    GIT_REPOSITORY "https://github.com/mthierman/pane.git"
    GIT_TAG "main"
)
FetchContent_MakeAvailable(pane)

add_executable(cpp)
target_sources(cpp PRIVATE "src/main.cpp" "src/app.cpp")
target_link_libraries(cpp PRIVATE pane::config pane::pane)
