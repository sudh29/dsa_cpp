#include <iostream>
#include <vector>

// Count unique paths from top-left to bottom-right in an m x n grid
int unique_paths(int m, int n) {
    std::vector<int> dp(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

int main() {
    std::cout << "=== Unique Grid Paths (Dynamic Programming) ===" << std::endl;
    int m = 3, n = 7;
    std::cout << "Grid " << m << "x" << n << " unique paths: " << unique_paths(m, n) << std::endl;
    return 0;
}
