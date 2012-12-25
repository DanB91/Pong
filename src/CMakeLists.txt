

set(ObjectFiles main.cpp)
add_subdirectory(Engine)



add_executable (pong ${ObjectFiles})
target_link_libraries(pong engine)
