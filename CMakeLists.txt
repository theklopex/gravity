cmake_minimum_required(VERSION 2.8)
project( Gravity )
add_executable (Gravity main.cpp Tuple.cpp Entity.cpp ForceVector.cpp EntityList.cpp)

#message(STATUS "PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR})
#message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR})
target_include_directories(Gravity PUBLIC "${PROJECT_SOURCE_DIR}")

add_subdirectory(test)

enable_testing()
