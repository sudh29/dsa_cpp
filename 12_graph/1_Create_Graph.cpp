#include <cassert>
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
    assert(adj.size() == 5);
    std::vector<int> expected0 = {1, 4};
    std::vector<int> expected1 = {0, 2, 3, 4};
    assert(adj[0] == expected0);
    assert(adj[1] == expected1);

    assert(printGraph(0, {}).empty());

    std::cout << "1_Create_Graph tests passed.\n";
    return 0;
}
