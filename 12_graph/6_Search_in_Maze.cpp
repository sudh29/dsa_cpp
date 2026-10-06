#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

void dfs(const std::vector<std::vector<int>>& m, int n, std::vector<std::string>& paths,
         std::string curr, int r, int c, std::vector<std::vector<bool>>& visited) {
    if (r < 0 || c < 0 || r >= n || c >= n) return;
    if (m[r][c] == 0 || visited[r][c]) return;

    if (r == n - 1 && c == n - 1) {
        paths.push_back(curr);
        return;
    }

    visited[r][c] = true;
    dfs(m, n, paths, curr + "D", r + 1, c, visited);
    dfs(m, n, paths, curr + "L", r, c - 1, visited);
    dfs(m, n, paths, curr + "R", r, c + 1, visited);
    dfs(m, n, paths, curr + "U", r - 1, c, visited);
    visited[r][c] = false;
}

std::vector<std::string> findPath(const std::vector<std::vector<int>>& m, int n) {
    std::vector<std::string> res;
    if (m.empty() || m[0][0] == 0 || m[n - 1][n - 1] == 0) return res;

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    dfs(m, n, res, "", 0, 0, visited);
    std::sort(res.begin(), res.end());
    return res;
}

int main() {
    std::vector<std::vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    auto paths = findPath(m, 4);
    std::vector<std::string> expected = {"DDRDRR", "DRDDRR"};
    assert(paths == expected);

    std::vector<std::vector<int>> blocked = {{0}};
    assert(findPath(blocked, 1).empty());

    std::cout << "6_Search_in_Maze tests passed.\n";
    return 0;
}
