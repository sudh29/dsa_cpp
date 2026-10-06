#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

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

    std::cout << "Graph Adjacency List:\n";
    g.printAdj();
    return 0;
}
