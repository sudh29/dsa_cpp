#include <iostream>
#include <vector>

bool dfs(int u, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, int parent) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, adj, visited, u)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, const std::vector<std::vector<int>>& adj) {
    std::vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, -1)) return true;
        }
    }
    return false;
}

int main() {
    int V = 5;
    std::vector<std::vector<int>> adj(V);
    // Cycle: 0-1-2-0
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};
    adj[3] = {2, 4};
    adj[4] = {3};

    std::cout << "Undirected graph has cycle: " << (isCycle(V, adj) ? "YES" : "NO") << "\n";

    std::vector<std::vector<int>> treeAdj(3);
    treeAdj[0] = {1};
    treeAdj[1] = {0, 2};
    treeAdj[2] = {1};
    std::cout << "Undirected tree has cycle: " << (isCycle(3, treeAdj) ? "YES" : "NO") << "\n";
    return 0;
}
