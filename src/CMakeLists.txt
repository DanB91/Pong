find_package(SDL REQUIRED)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(ObjectFiles main.cpp)
add_subdirectory(Engine)



add_executable (pong ${ObjectFiles})
target_link_libraries(pong engine)
