cmake_minimum_required(VERSION 3.12)
project(dcel
		VERSION 1.0
		LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
add_library(geomLib STATIC DCEL.cpp HalfEdge.hpp DCEL)
add_executable(dcel_test module_test.cpp)

target_link_libraries(dcel_test PRIVATE geomLib)