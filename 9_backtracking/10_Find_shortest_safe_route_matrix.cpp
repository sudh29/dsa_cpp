#include <cassert>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int findShortestPath(std::vector<std::vector<int>>& mat) {
    int R = static_cast<int>(mat.size());
    if (R == 0) return -1;
    int C = static_cast<int>(mat[0].size());

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
    int path_len = findShortestPath(mat);
    assert(path_len != -1);

    std::vector<std::vector<int>> empty;
    assert(findShortestPath(empty) == -1);

    std::cout << "10_Find_shortest_safe_route_matrix tests passed.\n";
    return 0;
}
