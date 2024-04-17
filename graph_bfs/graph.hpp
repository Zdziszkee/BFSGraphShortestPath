//
// Created by Kacper Kuchta on 4/13/24.
//

#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <list>
#include <queue>
#include <unordered_map>

class Graph
{
    size_t current_size = 0;
    std::unordered_map<std::string, std::list<std::string>> vertex_adjacency_list;

public:
    Graph() = default;

    void add_vertex(const std::string& vertex)
    {
        if (vertex_adjacency_list.contains(vertex))
        {
            throw std::runtime_error("This vertex already exists in this graph.");
        }

        vertex_adjacency_list[vertex] = std::list<std::string>();
        current_size++;
    }

    void add_vertex_neighbour(const std::string& vertex, const std::string& neighbour)
    {
        if (!vertex_adjacency_list.contains(vertex))
        {
            throw std::runtime_error("This vertex is not present in graph.");
        }
        vertex_adjacency_list[vertex].push_back(neighbour);
    }

    std::list<std::string> search_and_show_path(const std::string& start, const std::string& end)
    {
        std::queue<std::string> vertices;
        vertices.push(start);
        //vertex parent
        std::unordered_map<std::string, std::string> parents;
        //visited vertices and their distance from start
        std::unordered_map<std::string, size_t> visited;
        visited[start] = 0;

        while (!vertices.empty())
        {
            std::string vertex = vertices.front();
            vertices.pop();
            for (const auto& neighbour : vertex_adjacency_list[vertex])
            {
                if (!visited.contains(neighbour))
                {
                    vertices.push(neighbour);
                    visited[neighbour] = visited[vertex] + 1;
                    parents[neighbour] = vertex;
                }
                if (neighbour == end)
                {
                    std::list<std::string> shortest_path;
                    std::string current = neighbour;
                    while (parents.contains(current))
                    {
                        shortest_path.push_front(current);
                        current = parents[current];
                    }
                    shortest_path.push_front(start);
                    return shortest_path;
                }
            }
        }
        return {};
    }
};
#endif //GRAPH_HPP
