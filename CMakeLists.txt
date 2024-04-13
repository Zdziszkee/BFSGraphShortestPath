cmake_minimum_required(VERSION 3.28)
project(GraphBFS)

set(CMAKE_CXX_STANDARD 20)

add_executable(GraphBFS graph_bfs/main.cpp
        graph_bfs/Graph.hpp)
add_subdirectory(tests)
