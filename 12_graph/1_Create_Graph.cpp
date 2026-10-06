#include <iostream>
#include <vector>

std::vector<std::vector<int>> printGraph(int V, const std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> adj(V);
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

int main() {
    int V = 5;
    std::vector<std::vector<int>> edges = {
        {0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}
    };

    auto adj = printGraph(V, edges);
    std::cout << "Adjacency List Representation:\n";
    for (int i = 0; i < V; ++i) {
        std::cout << i << ": ";
        for (int neighbor : adj[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
