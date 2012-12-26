
set(CMAKE_CXX_LINK_FLAGS "-lcppunit")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
   set(CMAKE_CXX_LINK_FLAGS "-lcppunit")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

    
macro (make_test target src)
     add_executable(${target} ${src})
    target_link_libraries(${target} engine)
endmacro (make_test)

make_test(drawTest DrawTest.cpp)

make_test(keyboardTest KeyboardTest.cpp)
make_test(getComponentFromEntityTest EntityComponentTest.cpp)

