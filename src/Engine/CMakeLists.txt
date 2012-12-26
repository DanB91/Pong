
set(ObjectFiles GameEngine.cpp Canvas.cpp Sprite.cpp Keyboard.cpp Entity.cpp)
include_directories(${PROJECT_SOURCE_DIR})


add_library (engine ${ObjectFiles})
target_link_libraries(engine ${SDL_LIBRARY})


