cmake_minimum_required(VERSION 3.0.0)

if(CMAKE_BUILD_TYPE STREQUAL Release)
    set(MyProjectName network)
else()
    set(CMAKE_BUILD_TYPE Debug)
    set(MyProjectName network_debug)
endif()

message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "MyProjectName: ${MyProjectName}")

project(${MyProjectName})

aux_source_directory(. SRCS)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "../../../libs")

set(CMAKE_CXX_FLAGS "-Wall -std=c++14 -pthread")
set(CMAKE_CXX_FLAGS_DEBUG "-D_DEBUG -O0 -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

add_library(${MyProjectName} ${SRCS})
