cmake_minimum_required(VERSION 4.0)

project(cpp)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libs")

find_package(Config)
find_package(WIL)
find_package(Ada)
find_package(Glaze)

add_subdirectory("cpp")
