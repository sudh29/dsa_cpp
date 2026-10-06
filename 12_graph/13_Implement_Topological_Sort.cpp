#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

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
    assert(static_cast<int>(topo.size()) == V);

    std::vector<int> pos(V);
    for (size_t i = 0; i < topo.size(); ++i) {
        pos[topo[i]] = static_cast<int>(i);
    }
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            assert(pos[u] < pos[v]);
        }
    }

    assert(topoSort(0, {}).empty());

    std::cout << "13_Implement_Topological_Sort tests passed.\n";
    return 0;
}
