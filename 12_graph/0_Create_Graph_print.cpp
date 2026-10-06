#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Graph {
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adjList;

public:
    void addEdge(const std::string& u, const std::string& v, int dist, bool bidirectional = true) {
        adjList[u].push_back({v, dist});
        if (bidirectional) {
            adjList[v].push_back({u, dist});
        }
    }

    size_t numVertices() const {
        return adjList.size();
    }

    const auto& getAdj() const {
        return adjList;
    }

    void printAdj() const {
        for (const auto& [node, neighbors] : adjList) {
            std::cout << node << " : ";
            for (const auto& [neighbor, dist] : neighbors) {
                std::cout << "(" << neighbor << ", " << dist << ") ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Graph g;
    g.addEdge("0", "1", 4, false);
    g.addEdge("0", "7", 8, false);
    g.addEdge("1", "7", 11, false);
    g.addEdge("1", "2", 8, false);
    g.addEdge("7", "8", 7, false);

    assert(g.numVertices() == 3);
    const auto& adj = g.getAdj();
    assert(adj.at("0").size() == 2);
    assert(adj.at("1").size() == 2);
    assert(adj.at("7").size() == 1);

    std::cout << "0_Create_Graph_print tests passed.\n";
    return 0;
}
