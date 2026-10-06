#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

void dfs(int i, int j, std::string path, const std::vector<std::vector<int>>& mat, int n,
         std::vector<std::vector<bool>>& visited, std::vector<std::string>& ans) {
    if (i < 0 || j < 0 || i >= n || j >= n) return;
    if (mat[i][j] == 0 || visited[i][j]) return;
    if (i == n - 1 && j == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[i][j] = true;
    dfs(i - 1, j, path + "U", mat, n, visited, ans);
    dfs(i + 1, j, path + "D", mat, n, visited, ans);
    dfs(i, j - 1, path + "L", mat, n, visited, ans);
    dfs(i, j + 1, path + "R", mat, n, visited, ans);
    visited[i][j] = false;
}

std::vector<std::string> findPath(const std::vector<std::vector<int>>& mat, int n) {
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    std::vector<std::string> ans;
    if (mat[0][0] == 1 && mat[n - 1][n - 1] == 1) {
        dfs(0, 0, "", mat, n, visited, ans);
    }
    std::sort(ans.begin(), ans.end());
    if (ans.empty()) return {"-1"};
    return ans;
}

int main() {
    std::vector<std::vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = 4;
    auto paths = findPath(mat, n);
    std::vector<std::string> expected = {"DDRDRR", "DRDDRR"};
    assert(paths == expected);

    std::vector<std::vector<int>> blocked = {
        {0, 0},
        {0, 0}
    };
    assert(findPath(blocked, 2) == std::vector<std::string>{"-1"});

    std::cout << "0_Rat_maze_Problem tests passed.\n";
    return 0;
}
