#include <iostream>
#include <vector>
#include <queue>

struct Cell {
    int x, y, dist;
};

int minStepToReachTarget(std::pair<int, int> knightPos, std::pair<int, int> targetPos, int N) {
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    std::vector<std::vector<bool>> visited(N + 1, std::vector<bool>(N + 1, false));
    std::queue<Cell> q;

    q.push({knightPos.first, knightPos.second, 0});
    visited[knightPos.first][knightPos.second] = true;

    while (!q.empty()) {
        auto [x, y, dist] = q.front();
        q.pop();

        if (x == targetPos.first && y == targetPos.second) {
            return dist;
        }

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, dist + 1});
            }
        }
    }
    return -1;
}

int main() {
    int N = 6;
    std::pair<int, int> knight = {4, 5};
    std::pair<int, int> target = {1, 1};

    std::cout << "Minimum steps by Knight on " << N << "x" << N << ": "
              << minStepToReachTarget(knight, target, N) << " (expected 3)\n";
    return 0;
}
