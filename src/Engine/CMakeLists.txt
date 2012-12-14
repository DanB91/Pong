find_package(SDL REQUIRED)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(ObjectFiles GameEngine.cpp Canvas.cpp Sprite.cpp)
include_directories(${PROJECT_SOURCE_DIR})


add_library (engine ${ObjectFiles})
target_link_libraries(engine ${SDL_LIBRARY})

add_executable(drawTest tests/DrawTest.cpp)
target_link_libraries(drawTest engine)

add_test(DrawTest drawTest)
