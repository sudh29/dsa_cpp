#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>

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

    floydWarshall(dist, V);

    assert(dist[0][0] == 0);
    assert(dist[0][1] == 5);
    assert(dist[0][2] == 8);
    assert(dist[0][3] == 9);
    assert(dist[1][2] == 3);
    assert(dist[1][3] == 4);
    assert(dist[2][3] == 1);
    assert(dist[3][0] == INF);

    std::cout << "graph_floyd_warshall tests passed.\n";
    return 0;
}
