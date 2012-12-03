find_package(SDL REQUIRED)


set(ObjectFiles main.cpp)

add_executable (pong ${ObjectFiles})
target_link_libraries(pong ${SDL_LIBRARY})
