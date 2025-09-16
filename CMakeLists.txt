cmake_minimum_required(VERSION 4.0)

project(cpp)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libs")

find_package(Pane)

add_subdirectory("cpp")
