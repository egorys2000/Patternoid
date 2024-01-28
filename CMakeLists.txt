cmake_minimum_required(VERSION 3.22)
project(Patternoid)

option(BUILD_TESTS "Build tests" ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(src)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
