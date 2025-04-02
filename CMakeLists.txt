cmake_minimum_required(VERSION 3.20.0)

project(Graph VERSION 1.0.0 LANGUAGES C CXX)

include(CTest)

enable_testing()

add_executable(Graph src/edge.cpp src/graph.cpp tests/unitTestsGraph.cpp tests/catch_amalgamated.cpp)

set_property(TARGET Graph PROPERTY CXX_STANDARD 17)