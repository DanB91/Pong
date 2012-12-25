macro (make_test target src)
     add_executable(${target} ${src})
    target_link_libraries(${target} engine)
endmacro (make_test)

make_test(drawTest DrawTest.cpp)

make_test(keyboardTest KeyboardTest.cpp)
make_test(spriteDrawableComponentTest SpriteDrawableComponentTest.cpp)
