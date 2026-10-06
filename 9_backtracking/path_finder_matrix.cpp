#include <cassert>
#include <iostream>
#include <utility>
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

    bool found = matrix[0][0] == 1 && findPath(matrix, 0, 0, n, path);
    assert(found);
    assert(path.front() == (std::pair<int, int>{0, 0}));
    assert(path.back() == (std::pair<int, int>{4, 4}));

    std::vector<std::vector<int>> blocked = {{0}};
    std::vector<std::pair<int, int>> p2;
    assert(!(blocked[0][0] == 1 && findPath(blocked, 0, 0, 1, p2)));

    std::cout << "path_finder_matrix tests passed.\n";
    return 0;
}
