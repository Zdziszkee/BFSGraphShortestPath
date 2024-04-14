#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

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
    std::list<std::string> path;
    std::unordered_map<std::string, std::list<std::string>> paths;
    std::string path_vertice;
    for (int i = 0; i < path_amount; ++i)
    {
        std::string line;
        // Read words until '\n' appears
        std::getline(std::cin, line);
        std::istringstream string_stream(line);
        string_stream >> path_name;
        while (string_stream >> path_vertice)
        {
            string_stream >> path_vertice;
            path.push_back(path_vertice);
        }
        paths[path_name] = path;
        path.clear();
    }

    std::string start_vertice;
    std::string end_vertice;
    std::cin >> start_vertice;
    std::cin >> end_vertice;
    return 0;
}
