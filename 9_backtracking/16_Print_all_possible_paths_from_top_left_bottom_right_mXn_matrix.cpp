#include <iostream>
#include <vector>
#include <string>

void findPaths(int r, int c, int m, int n, std::string path, std::vector<std::string>& all_paths) {
    if (r == m - 1 && c == n - 1) {
        all_paths.push_back(path);
        return;
    }
    if (r + 1 < m) {
        findPaths(r + 1, c, m, n, path + "D", all_paths);
    }
    if (c + 1 < n) {
        findPaths(r, c + 1, m, n, path + "R", all_paths);
    }
}

long long numberOfPaths(int m, int n) {
    std::vector<std::vector<long long>> dp(m, std::vector<long long>(n, 1));
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    int m = 3, n = 3;
    std::vector<std::string> paths;
    findPaths(0, 0, m, n, "", paths);
    std::cout << "Number of paths for " << m << "x" << n << ": " << numberOfPaths(m, n) << "\n";
    std::cout << "All paths:\n";
    for (const auto& p : paths) {
        std::cout << "  " << p << "\n";
    }
    return 0;
}
