#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

class GraphAdjMatrix {
private:
    int size;
    std::vector<std::vector<int>> matrix;

public:
    GraphAdjMatrix(int n) : size(n), matrix(n, std::vector<int>(n, 0)) {}

    void addEdge(int u, int v) {
        if (u >= 0 && u < size && v >= 0 && v < size) {
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
    }

    std::vector<int> bfs(int source) {
        std::vector<int> path;
        if (size <= 0 || source < 0 || source >= size) return path;
        std::vector<bool> visited(size, false);
        std::queue<int> q;

        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            path.push_back(u);

            for (int v = 0; v < size; ++v) {
                if (matrix[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return path;
    }

    void printMatrix() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    GraphAdjMatrix g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);

    auto traversal = g.bfs(0);
    std::vector<int> expected = {0, 1, 2, 3, 4, 5};
    assert(traversal == expected);

    assert(g.bfs(-1).empty());

    std::cout << "graph_adj_matrix_bfs tests passed.\n";
    return 0;
}
