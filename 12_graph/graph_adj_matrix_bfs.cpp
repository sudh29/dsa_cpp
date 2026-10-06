#include <iostream>
#include <vector>
#include <queue>

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

    std::cout << "Adjacency Matrix:\n";
    g.printMatrix();

    std::cout << "\nBFS from 0: ";
    auto traversal = g.bfs(0);
    for (int node : traversal) std::cout << node << " ";
    std::cout << "\n";
    return 0;
}
