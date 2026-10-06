#include <iostream>
#include <vector>

void dfsUtil(int u, std::vector<bool>& visited, const std::vector<std::vector<int>>& adj,
             std::vector<int>& res) {
    visited[u] = true;
    res.push_back(u);

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsUtil(v, visited, adj, res);
        }
    }
}

std::vector<int> dfsOfGraph(int V, const std::vector<std::vector<int>>& adj) {
    std::vector<int> res;
    if (V < 1) return res;

    std::vector<bool> visited(V, false);
    dfsUtil(0, visited, adj, res);
    return res;
}

int main() {
    int V = 5;
    std::vector<std::vector<int>> adj(V);
    adj[0] = {1, 2, 4};
    adj[1] = {0};
    adj[2] = {0};
    adj[3] = {4};
    adj[4] = {0, 3};

    auto dfs = dfsOfGraph(V, adj);
    std::cout << "DFS Traversal: ";
    for (int node : dfs) std::cout << node << " ";
    std::cout << "\n";
    return 0;
}
