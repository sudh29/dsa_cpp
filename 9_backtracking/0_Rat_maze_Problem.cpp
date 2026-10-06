#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
    std::cout << "Rat in a maze paths: ";
    for (const auto& p : paths) std::cout << p << " ";
    std::cout << "\n";
    return 0;
}
