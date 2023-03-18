cmake_minimum_required(VERSION 2.8)
project( Gravity )
add_executable (Gravity main.cpp)

#message(STATUS "PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR})
#message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR})
target_include_directories(Gravity PUBLIC "${PROJECT_SOURCE_DIR}")

add_library(Tuple Tuple.cpp)
target_link_libraries(Gravity Tuple)

add_library(Entity Entity.cpp)
target_link_libraries(Gravity Entity)

add_library(Vector Vector.cpp)
target_link_libraries(Gravity Vector)

add_subdirectory(test)