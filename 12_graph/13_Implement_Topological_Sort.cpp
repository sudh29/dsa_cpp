#include <iostream>
#include <vector>
#include <queue>

// Kahn's Algorithm (BFS based topological sort)
std::vector<int> topoSort(int V, const std::vector<std::vector<int>>& adj) {
    std::vector<int> inDegree(V, 0);
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    std::queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    std::vector<int> res;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.push_back(u);

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    return res;
}

int main() {
    int V = 6;
    std::vector<std::vector<int>> adj(V);
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    auto topo = topoSort(V, adj);
    std::cout << "Topological Sort order: ";
    for (int u : topo) std::cout << u << " ";
    std::cout << "\n";
    return 0;
}
