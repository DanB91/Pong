add_executable(drawTest DrawTest.cpp)
target_link_libraries(drawTest engine)
add_test(DrawTest drawTest)

add_executable(keyboardTest KeyboardTest.cpp)
target_link_libraries(keyboardTest engine)
add_test(KeyboardTest keyboardTest ~/Documents/Untitled.bmp)

