cmake_minimum_required(VERSION 4.0)
project(cpp)

include(FetchContent)
FetchContent_Declare(
    cmake-modules
    GIT_REPOSITORY "https://github.com/mthierman/cmake-modules.git"
    GIT_TAG "main"
)
FetchContent_MakeAvailable(cmake-modules)

find_package(Pane)

add_subdirectory("cpp")
