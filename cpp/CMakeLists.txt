add_executable(cpp)
target_sources(cpp PRIVATE "src/main.cpp")
target_link_libraries(cpp PRIVATE pane::pane)
