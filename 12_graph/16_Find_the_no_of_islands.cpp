#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<char>>& grid, int r, int c, int n, int m) {
    if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] != '1') return;

    grid[r][c] = '0'; // mark visited

    // 8 directions
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int d = 0; d < 8; ++d) {
        dfs(grid, r + dr[d], c + dc[d], n, m);
    }
}

int numIslands(std::vector<std::vector<char>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, n, m);
            }
        }
    }
    return count;
}

int main() {
    std::vector<std::vector<char>> grid = {
        {'0', '1', '1', '1', '0', '0', '0'},
        {'0', '0', '1', '1', '0', '1', '0'}
    };

    std::cout << "Number of islands (8-connected): " << numIslands(grid) << " (expected 2)\n";
    return 0;
}
