cmake_minimum_required (VERSION 2.6)
project (Pong)

find_package(SDL REQUIRED)
find_package(SDL_Image REQUIRED)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_CXX_FLAGS "-std=c++11 -g")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
#   set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ -g")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")


include_directories(src)

add_subdirectory(src bin)
