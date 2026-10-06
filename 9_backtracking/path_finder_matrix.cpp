#include <iostream>
#include <vector>

bool findPath(const std::vector<std::vector<int>>& mat, int x, int y, int n,
              std::vector<std::pair<int, int>>& path) {
    if (x == n - 1 && y == n - 1) {
        path.push_back({x, y});
        return true;
    }

    path.push_back({x, y});

    // Try moving Down
    if (x + 1 < n && mat[x + 1][y] == 1) {
        if (findPath(mat, x + 1, y, n, path)) return true;
    }

    // Try moving Right
    if (y + 1 < n && mat[x][y + 1] == 1) {
        if (findPath(mat, x, y + 1, n, path)) return true;
    }

    path.pop_back(); // Backtrack
    return false;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    int n = 5;
    std::vector<std::pair<int, int>> path;

    if (matrix[0][0] == 1 && findPath(matrix, 0, 0, n, path)) {
        std::cout << "Path found: ";
        for (const auto& pt : path) {
            std::cout << "(" << pt.first << ", " << pt.second << ") ";
        }
        std::cout << "\n";
    } else {
        std::cout << "No path exists\n";
    }
    return 0;
}
