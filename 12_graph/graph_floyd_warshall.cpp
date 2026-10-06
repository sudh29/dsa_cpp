#include <iostream>
#include <vector>
#include <iomanip>

const long long INF = 1e9;

void floydWarshall(std::vector<std::vector<long long>>& dist, int V) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int V = 4;
    std::vector<std::vector<long long>> dist(V, std::vector<long long>(V, INF));

    for (int i = 0; i < V; ++i) dist[i][i] = 0;
    dist[0][1] = 5;
    dist[0][3] = 10;
    dist[1][2] = 3;
    dist[2][3] = 1;

    std::cout << "Original distance matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) std::cout << "INF ";
            else std::cout << std::setw(3) << dist[i][j] << " ";
        }
        std::cout << "\n";
    }

    floydWarshall(dist, V);

    std::cout << "\nAll-pairs shortest distances (Floyd-Warshall):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) std::cout << "INF ";
            else std::cout << std::setw(3) << dist[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
