find_package(CppUnit REQUIRED)
include_directories(${CPPUNIT_INCLUDE_DIRS})
set(LIBS ${LIBS} ${CPPUNIT_LIBRARIES} engine)

macro (make_test target src)
     add_executable(${target} ${src})
    target_link_libraries(${target} ${LIBS})
endmacro (make_test)

make_test(drawTest DrawTest.cpp)

make_test(keyboardTest KeyboardTest.cpp)
make_test(getComponentFromEntityTest EntityComponentTest.cpp)

