#include <iostream>
#include <vector>

void dfs(int u, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int makeConnected(int n, const std::vector<std::vector<int>>& connections) {
    if (static_cast<int>(connections.size()) < n - 1) {
        return -1; // Not enough cables
    }

    std::vector<std::vector<int>> adj(n);
    for (const auto& conn : connections) {
        adj[conn[0]].push_back(conn[1]);
        adj[conn[1]].push_back(conn[0]);
    }

    std::vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }

    return components - 1;
}

int main() {
    int n = 4;
    std::vector<std::vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    std::cout << "Minimum operations to make connected (n=4): "
              << makeConnected(n, connections) << " (expected 1)\n";

    int n2 = 6;
    std::vector<std::vector<int>> connections2 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    std::cout << "Minimum operations (n=6): "
              << makeConnected(n2, connections2) << " (expected 2)\n";
    return 0;
}
