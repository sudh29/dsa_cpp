#include <iostream>
#include <vector>

bool dfs(int u, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited,
         std::vector<bool>& recStack) {
    visited[u] = true;
    recStack[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, adj, visited, recStack)) return true;
        } else if (recStack[v]) {
            return true;
        }
    }

    recStack[u] = false;
    return false;
}

bool isCyclic(int V, const std::vector<std::vector<int>>& adj) {
    std::vector<bool> visited(V, false);
    std::vector<bool> recStack(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) return true;
        }
    }
    return false;
}

int main() {
    int V = 4;
    std::vector<std::vector<int>> adj(V);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // Cycle: 1->2->3->1

    std::cout << "Directed graph contains cycle: " << (isCyclic(V, adj) ? "YES" : "NO") << "\n";

    std::vector<std::vector<int>> acyclicAdj(3);
    acyclicAdj[0].push_back(1);
    acyclicAdj[1].push_back(2);
    std::cout << "Acyclic graph contains cycle: " << (isCyclic(3, acyclicAdj) ? "YES" : "NO") << "\n";
    return 0;
}
