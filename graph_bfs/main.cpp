#include <iostream>
#include <list>
#include <string>
#include "graph.hpp"


int main()
{
    Graph graph = Graph::get_graph_from_stream(std::cin);

    std::string start_vertice;
    std::string end_vertice;
    std::cin >> start_vertice;
    std::cin >> end_vertice;

    const auto shortest_path = graph.get_shortest_path(start_vertice, end_vertice);
    if (shortest_path.empty())
    {
        std::cout << "NO ROUTE" << std::endl;
    }
    else
    {
        for (const auto& node : shortest_path)
        {
            std::cout << node << " ";
        }
    }

    return 0;
}
