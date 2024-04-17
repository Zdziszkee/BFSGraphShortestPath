//
// Created by Kacper Kuchta on 4/13/24.
//
#include "../graph_bfs_shortest_path/graph.hpp"
#include <fstream>
#include "gtest/gtest.h"
TEST(GraphShortestPathTest, ExampleGraph1)
{
    // 12/2/2020 -> 737761
    std::ifstream file("tests/test_input_1");
    Graph graph = Graph::get_graph_from_stream(file);
    std::string start_vertice;
    std::string end_vertice;
    file >> start_vertice;
    file >> end_vertice;
    file.close();

    std::list<std::string> path = graph.get_shortest_path(start_vertice, end_vertice);
    std::list<std::string> expected = {"Quackville", "NoodlePark", "Sneezewind", "FluffyFalls"};
    EXPECT_EQ(path, expected);
}
TEST(GraphShortestPathTest, ExampleGraph2)
{
    // 12/2/2020 -> 737761
    std::ifstream file("tests/test_input_2");
    Graph graph = Graph::get_graph_from_stream(file);
    std::string start_vertice;
    std::string end_vertice;
    file >> start_vertice;
    file >> end_vertice;
    file.close();

    std::list<std::string> path = graph.get_shortest_path(start_vertice, end_vertice);
    std::list<std::string> expected = {};
    EXPECT_EQ(path, expected);
}
