#include <iostream>
#include <vector>

bool isValid(int node, const std::vector<std::vector<int>>& graph, const std::vector<int>& color, int c, int V) {
    for (int i = 0; i < V; ++i) {
        if (graph[node][i] && color[i] == c) return false;
    }
    return true;
}

bool solve(int node, int m, std::vector<int>& color, const std::vector<std::vector<int>>& graph, int V) {
    if (node == V) return true;

    for (int c = 1; c <= m; ++c) {
        if (isValid(node, graph, color, c, V)) {
            color[node] = c;
            if (solve(node + 1, m, color, graph, V)) return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(const std::vector<std::vector<int>>& graph, int m, int V) {
    std::vector<int> color(V, 0);
    return solve(0, m, color, graph, V);
}

int main() {
    int V = 4;
    int m = 3;
    std::vector<std::vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    std::cout << "Can graph be colored with " << m << " colors? "
              << (graphColoring(graph, m, V) ? "Yes (1)" : "No (0)") << "\n";
    return 0;
}
