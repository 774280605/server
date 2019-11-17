cmake_minimum_required(VERSION 3.15)
project(server)

option(SYSTEM_APPLE "this system is apple" OFF)
option(SYSTEM_WIN32 "this system is win32" OFF)






set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)


#添加源码路径
aux_source_directory(src SRC_LISTS)
aux_source_directory(src/reactor SRC_LISTS)
#添加main函数到源码中
list(APPEND SRC_LISTS main.cpp)
add_executable(server ${SRC_LISTS})