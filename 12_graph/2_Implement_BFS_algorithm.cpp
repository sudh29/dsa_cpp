#include <iostream>
#include <vector>
#include <queue>

std::vector<int> bfsOfGraph(int V, const std::vector<std::vector<int>>& adj) {
    std::vector<int> res;
    if (V < 1) return res;

    std::vector<bool> visited(V, false);
    std::queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.push_back(u);

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return res;
}

int main() {
    int V = 5;
    std::vector<std::vector<int>> adj(V);
    adj[0] = {1, 2, 3};
    adj[2] = {4};

    auto bfs = bfsOfGraph(V, adj);
    std::cout << "BFS Traversal: ";
    for (int node : bfs) std::cout << node << " ";
    std::cout << "\n";
    return 0;
}
