#include <cassert>
#include <iostream>
#include <vector>

/**
 * Problem: Unique Grid Paths (Dynamic Programming)
 * Module: 0_basics
 * Time Complexity: O(m * n)
 * Space Complexity: O(n)
 */

int unique_paths(int m, int n) {
    if (m <= 0 || n <= 0) return 0;
    std::vector<int> dp(n, 1);
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

int main() {
    assert(unique_paths(3, 7) == 28);
    assert(unique_paths(3, 2) == 3);
    assert(unique_paths(1, 1) == 1);
    assert(unique_paths(1, 10) == 1);
    assert(unique_paths(10, 1) == 1);
    assert(unique_paths(0, 5) == 0);

    std::cout << "[PASS] 0_basics/cpp_grid_paths: all tests passed!\n";
    return 0;
}
