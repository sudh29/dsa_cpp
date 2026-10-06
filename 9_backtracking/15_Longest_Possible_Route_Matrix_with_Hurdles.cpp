#include <iostream>
#include <vector>
#include <algorithm>

void solve(const std::vector<std::vector<int>>& mat, int n, int m, int r, int c,
           int dr, int dc, std::vector<std::vector<bool>>& visited, int curr, int& max_len) {
    if (r == dr && c == dc) {
        max_len = std::max(max_len, curr);
        return;
    }

    visited[r][c] = true;
    int dirR[] = {0, 1, 0, -1};
    int dirC[] = {1, 0, -1, 0};

    for (int d = 0; d < 4; ++d) {
        int nr = r + dirR[d];
        int nc = c + dirC[d];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1 && !visited[nr][nc]) {
            solve(mat, n, m, nr, nc, dr, dc, visited, curr + 1, max_len);
        }
    }
    visited[r][c] = false; // backtrack
}

int longestPath(const std::vector<std::vector<int>>& mat, int n, int m, int xs, int ys, int xd, int yd) {
    if (mat[xs][ys] == 0 || mat[xd][yd] == 0) return -1;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    int max_len = -1;
    solve(mat, n, m, xs, ys, xd, yd, visited, 0, max_len);
    return max_len;
}

int main() {
    std::vector<std::vector<int>> mat = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    int n = 3, m = 10;
    std::cout << "Longest path length: " << longestPath(mat, n, m, 0, 0, 1, 7) << " (expected 24)\n";
    return 0;
}
