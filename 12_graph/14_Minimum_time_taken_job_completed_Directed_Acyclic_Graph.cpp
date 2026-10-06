#include <iostream>
#include <vector>
#include <queue>

std::vector<int> minimumTime(int n, int m, const std::vector<std::vector<int>>& edges) {
    (void)m;
    std::vector<std::vector<int>> adj(n + 1);
    std::vector<int> inDegree(n + 1, 0);

    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        inDegree[v]++;
    }

    std::queue<int> q;
    std::vector<int> time(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
            time[i] = 1;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                time[v] = time[u] + 1;
                q.push(v);
            }
        }
    }

    std::vector<int> result(time.begin() + 1, time.end());
    return result;
}

int main() {
    int n = 10, m = 13;
    std::vector<std::vector<int>> edges = {
        {1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 8}, {2, 9},
        {3, 6}, {4, 6}, {4, 8}, {5, 8}, {6, 7}, {7, 8}, {8, 10}
    };

    auto ans = minimumTime(n, m, edges);
    std::cout << "Minimum time taken by jobs 1.." << n << ":\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Job " << (i + 1) << ": " << ans[i] << " unit(s)\n";
    }
    return 0;
}
