#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int findShortestPath(std::vector<std::vector<int>>& mat) {
    int R = mat.size();
    if (R == 0) return -1;
    int C = mat[0].size();

    // Mark unsafe cells
    std::vector<std::vector<int>> safe = mat;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (mat[r][c] == 0) {
                safe[r][c] = 0;
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                        safe[nr][nc] = 0;
                    }
                }
            }
        }
    }

    // BFS from all safe cells in column 0
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> dist(R, std::vector<int>(C, -1));

    for (int r = 0; r < R; ++r) {
        if (safe[r][0] == 1) {
            q.push({r, 0});
            dist[r][0] = 1;
        }
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (c == C - 1) {
            return dist[r][c];
        }

        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && safe[nr][nc] == 1 && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    return -1;
}

int main() {
    std::vector<std::vector<int>> mat = {
        {1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };
    std::cout << "Shortest safe path length: " << findShortestPath(mat) << "\n";
    return 0;
}
