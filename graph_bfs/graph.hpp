//
// Created by Kacper Kuchta on 4/13/24.
//

#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <list>
#include <queue>
#include <set>

template <class T>
class Graph
{
public:
    class Vertice
    {
    protected:
        T value;
        std::list<Vertice> neighbours;

    public:
        Vertice(const T value, const std::list<Vertice>& neighbours)
            : value(value),
              neighbours(neighbours)
        {
        }
    };

private:
    std::list<Vertice> vertices;

    std::list<Vertice&> find_shortest_path(Vertice& a, Vertice& b)
    {
        std::set<Vertice&> visited;
        std::queue<Vertice&> queue;



    }

    std::optional<Vertice&> get_vertice_by_value(T& value)
    {
        std::optional<Vertice&> result;
        for (auto vertex& : vertices)
        {
            if (value == vertex.value)
            {
                result = vertex;
                break;
            }
        }
        return std::nullopt;
    }
};
#endif //GRAPH_HPP
