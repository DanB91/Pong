

set(ObjectFiles main.cpp GameplayState.cpp)
add_subdirectory(Engine)
add_subdirectory(tests tests)


add_executable (pong ${ObjectFiles})
target_link_libraries(pong engine)
