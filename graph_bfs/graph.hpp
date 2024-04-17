//
// Created by Kacper Kuchta on 4/13/24.
//

#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <list>
#include <queue>
#include <unordered_map>
#include <sstream>
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

    std::list<std::string> get_shortest_path(const std::string& start, const std::string& end)
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

    static Graph get_graph_from_stream(std::istream& stream)
    {
        size_t vertex_amount;
        stream >> vertex_amount;

        std::vector<std::string> vertices;
        std::string vertex;
        for (int i = 0; i < vertex_amount; ++i)
        {
            stream >> vertex;
            vertices.push_back(vertex);
        }

        size_t path_amount;
        stream >> path_amount;

        std::string path_name;
        std::vector<std::string> path;
        std::unordered_map<std::string, std::vector<std::string>> paths;
        std::string path_vertice;
        stream.ignore();
        for (int i = 0; i < path_amount; ++i)
        {
            std::string line;
            // Read words until '\n' appears
            std::getline(stream, line);
            std::istringstream string_stream(line);
            string_stream >> path_name;
            while (string_stream >> path_vertice)
            {
                path.push_back(path_vertice);
            }
            paths[path_name] = path;
            path.clear();
        }


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
        return graph;
    }
};
#endif //GRAPH_HPP
