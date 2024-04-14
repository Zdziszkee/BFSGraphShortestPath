//
// Created by Kacper Kuchta on 4/13/24.
//

#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <list>
#include <optional>
#include <queue>
#include <set>
#include <unordered_map>

template <class T>
class Graph
{
public:
    class Vertex
    {
        T value;
        std::list<Vertex> neighbours;

    public:
        explicit Vertex(const T value)
            : value(value)
        {
        }

        void add_neighbour(Vertex vertex)
        {
            neighbours.emplace(vertex);
        }
    };

private:
    //adj list
    const size_t size;
    size_t current_size = 0;
    Vertex* vertex_adjacency_list;

public:
    explicit Graph(const size_t size)
        : size(size), vertex_adjacency_list(new Vertex[size])
    {
    }

    void add_vertex(Vertex vertex)
    {
        if (current_size >= size)
        {
            throw std::overflow_error("Graph has reached maximum amount of vertices");
        }
        vertex_adjacency_list[current_size] = vertex;
        current_size++;
    }

    void add_vertex_neighbour(Vertex& vertex, Vertex& neighbour)
    {
        for (int i = 0; i < current_size; ++i)
        {
            if (vertex.value == vertex_adjacency_list[i].value)
            {
                vertex_adjacency_list[i].add_neighbour(neighbour);
            }
        }
        throw std::runtime_error("Could not find vertex with that value.");
    }

    std::list<Vertex&> search_and_show_path(Vertex& start, Vertex& end)
    {
        std::queue<Vertex&> vertices;
        vertices.push(start);
        //vertice parent
        std::unordered_map<Vertex&, Vertex&> parents;
        //visited vertices and their distance from start
        std::unordered_map<Vertex&, size_t> visited;
        visited[start] = 0;

        while (!vertices.empty())
        {
            Vertex& vertex = vertices.front();
            vertices.pop();
            for (auto& neighbour : vertex.neighbours)
            {
                if (!visited.contains(neighbour))
                {
                    vertices.push(neighbour);
                    visited[neighbour] = visited[vertex] + 1;
                    parents[neighbour] = vertex;
                }
                if (neighbour == end)
                {
                    std::list<Vertex&> shortest_path;
                    Vertex& current = neighbour;
                    while (parents.contains(current))
                    {
                        shortest_path.push_front(current);
                        current = parents[current];
                    }
                    return shortest_path;
                }
            }
        }
        return new std::list<Vertex&>;
    }

    std::optional<Vertex&> get_vertice_by_value(T& value)
    {
        std::optional<Vertex&> result;
        for (int i = 0; i < current_size; ++i)
        {
            if (vertex_adjacency_list[i].value == value)
            {
                result = vertex_adjacency_list[i];
                return result;
            }
        }
        return std::nullopt;
    }
};
#endif //GRAPH_HPP
