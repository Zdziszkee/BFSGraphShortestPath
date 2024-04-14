//
// Created by Kacper Kuchta on 4/13/24.
//

#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <list>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>

template<class T>
class Graph {
public:
    class Vertice {
    public:
        T value;
        std::list<Vertice> neighbours;

    public:
        Vertice(const T value, const std::list<Vertice> &neighbours)
            : value(value),
              neighbours(neighbours) {
        }
    };

private:
    //TODO change to neighbour list
    Vertice root;


    }

    void search_and_show_path(Vertice &start, Vertice &end) {
        std::queue<Vertice &> vertices;
        vertices.push(start);
        //vertice parent
        std::unordered_map<Vertice &, Vertice &> parents;
        //visited vertices and their distance from a
        std::unordered_map<Vertice &, size_t> visited;
        visited[start] = 0;

        while (!vertices.empty()) {
            Vertice& vertex = vertices.front();
            vertices.pop();
            for (auto &neighbour: vertex.neighbours) {
                if (!visited.contains(neighbour)) {
                    vertices.push(neighbour);
                    visited[neighbour] = visited[vertex] + 1;
                    parents[neighbour] = vertex;
                }
                if (neighbour == end) {
                    //TODO back track and return list
                    break;
                }
            }
        }
    //TODO return empty list
        // show path from t to s
        for (; end != -1; end = parents[end])
            std::cout << end + 1 << " ";
    }

    std::optional<Vertice &> get_vertice_by_value(T &value) {
        std::optional<Vertice &> result;
        std::stack<Vertice &> vertices;
        vertices.push(this->root);

        while (!vertices.empty()) {
            const auto &vertex = vertices.top();
            if (value == vertex.value) {
                result = vertex;
                return result;
            }
            for (const auto &neighbour: vertex.neighbours) {
                vertices.push(neighbour);
            }
        }
        return std::nullopt;
    }
};
#endif //GRAPH_HPP
