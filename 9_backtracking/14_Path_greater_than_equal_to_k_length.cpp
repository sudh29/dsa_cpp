#include <iostream>
#include <vector>
#include <vector>

bool dfs(int u, std::vector<bool>& visited, const std::vector<std::vector<std::pair<int, int>>>& adj,
         int path_len, int K) {
    if (path_len >= K) return true;

    visited[u] = true;
    for (const auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (!visited[v]) {
            if (dfs(v, visited, adj, path_len + w, K)) {
                return true;
            }
        }
    }
    visited[u] = false; // backtrack
    return false;
}

bool pathMoreThanK(int V, int K, const std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<std::pair<int, int>>> adj(V);
    for (const auto& e : edges) {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    std::vector<bool> visited(V, false);
    return dfs(0, visited, adj, 0, K);
}

int main() {
    int V = 9;
    int K = 60;
    std::vector<std::vector<int>> edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9},
        {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 8, 7}
    };

    std::cout << "Path of weight >= " << K << " exists from 0: "
              << (pathMoreThanK(V, K, edges) ? "YES (1)" : "NO (0)") << "\n";
    return 0;
}
