cmake_minimum_required(VERSION 3.0.0)

if(CMAKE_BUILD_TYPE STREQUAL Release)
    set(MyProjectName server)
    set(MyLibNetWorkName network.a)
else()
    set(CMAKE_BUILD_TYPE Debug)
    set(MyProjectName server_debug)
    set(MyLibNetWorkName network_debug.a)
endif()

message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "ProjectName: ${MyProjectName}")
message(STATUS "NetworklibName: ${MyLibNetWorkName}")

project(${MyProjectName})

aux_source_directory(. SRCS)

include_directories(../../libs)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../../bin")
set(CMAKE_CXX_FLAGS "-Wall -std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "-D_DEBUG -O0 -g -ggdb")  
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

link_directories(${CMAKE_BINARY_DIR}/../../../libs)

add_executable(${MyProjectName} ${SRCS})

target_link_libraries(${MyProjectName} ${MyLibNetWorkName}) 