cmake_minimum_required(VERSION 3.20.0)

project(Graph VERSION 1.0.0 LANGUAGES C CXX)

include(CTest)

enable_testing()

add_executable(Graph tests/catch_amalgamated.cpp src/edge.cpp src/location.cpp tests/unitTestsGraph.cpp )

set_property(TARGET Graph PROPERTY CXX_STANDARD 17)