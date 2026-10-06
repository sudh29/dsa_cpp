#include <iostream>
#include <vector>
#include <queue>
#include <climits>

std::vector<int> dijkstra(int V, const std::vector<std::vector<std::pair<int, int>>>& adj, int S) {
    std::vector<int> dist(V, INT_MAX);
    // Min-heap: {distance, node}
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V = 3;
    std::vector<std::vector<std::pair<int, int>>> adj(V);
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 6});
    adj[1].push_back({2, 3});
    adj[1].push_back({0, 1});
    adj[2].push_back({1, 3});
    adj[2].push_back({0, 6});

    auto distances = dijkstra(V, adj, 2);
    std::cout << "Distances from source 2: ";
    for (int d : distances) std::cout << d << " ";
    std::cout << "\n";
    return 0;
}
