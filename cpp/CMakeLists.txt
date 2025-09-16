add_executable(cpp)
target_sources(cpp PRIVATE "src/main.cpp" "src/cpp.cpp")
target_link_libraries(cpp PRIVATE pane::config pane::pane)
