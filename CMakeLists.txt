cmake_minimum_required(VERSION 3.15)
project(server)

option(SYSTEM_APPLE "this system is apple" OFF)
option(SYSTEM_WIN32 "this system is win32" OFF)






set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)


#添加源码路径
aux_source_directory(src SRC_LISTS)
if(APPLE)
    message("this system is APPLE")
    list(APPEND SRC_LISTS src/reactor/KReactor.h src/reactor/KReactor.cpp)
endif()
list(APPEND SRC_LISTS src/reactor/Reactor.h src/reactor/Reactor.cpp src/reactor/ReactorImpl.h src/reactor/ReactorImpl.cpp
        src/reactor/SelectReactorImpl.cpp src/reactor/SelectReactorImpl.h)


aux_source_directory(src/activeobject SRC_LISTS)
aux_source_directory(src/queue SRC_LISTS)
#添加main函数到源码中
list(APPEND SRC_LISTS main.cpp)
add_executable(server ${SRC_LISTS})

if (WIN32)
    target_link_libraries(server ws2_32)
endif ()