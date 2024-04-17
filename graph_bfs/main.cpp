#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "graph.hpp"

int main()
{
    size_t vertex_amount;
    std::cin >> vertex_amount;

    std::vector<std::string> vertices;
    std::string vertex;
    for (int i = 0; i < vertex_amount; ++i)
    {
        std::cin >> vertex;
        vertices.push_back(vertex);
    }

    size_t path_amount;
    std::cin >> path_amount;

    std::string path_name;
    std::vector<std::string> path;
    std::unordered_map<std::string, std::vector<std::string>> paths;
    std::string path_vertice;
    std::cin.ignore();
    for (int i = 0; i < path_amount; ++i)
    {
        std::string line;
        // Read words until '\n' appears
        std::getline(std::cin, line);
        std::istringstream string_stream(line);
        string_stream >> path_name;
        while (string_stream >> path_vertice)
        {
            path.push_back(path_vertice);
        }
        paths[path_name] = path;
        path.clear();
    }

    std::string start_vertice;
    std::string end_vertice;
    std::cin >> start_vertice;
    std::cin >> end_vertice;

    Graph graph;

    for (const auto& value : vertices)
    {
        graph.add_vertex(value);
    }
    for (const auto& pair : paths)
    {
        const auto list = pair.second;
        for (int i = 0; i < list.size() - 1; ++i)
        {
            const auto& current = list[i];
            const auto& next = list[i + 1];
            graph.add_vertex_neighbour(current, next);
        }
    }
    const auto shortest_path = graph.search_and_show_path(start_vertice, end_vertice);
    for (const auto& node : shortest_path)
    {
        std::cout << node << " ";
    }
    return 0;
}
