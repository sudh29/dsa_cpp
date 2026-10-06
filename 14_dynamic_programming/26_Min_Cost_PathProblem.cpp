#include <iostream>
#include <vector>
#include <algorithm>

int maximumPath(int n, const std::vector<std::vector<int>>& mat) {
    std::vector<std::vector<int>> dp = mat;

    for (int r = 1; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            int left_up = (c > 0) ? dp[r - 1][c - 1] : 0;
            int up = dp[r - 1][c];
            int right_up = (c < n - 1) ? dp[r - 1][c + 1] : 0;
            dp[r][c] += std::max({left_up, up, right_up});
        }
    }
    int max_val = 0;
    for (int c = 0; c < n; ++c) {
        max_val = std::max(max_val, dp[n - 1][c]);
    }
    return max_val;
}

int main() {
    std::vector<std::vector<int>> mat = {
        {348, 391},
        {618, 420}
    };
    std::cout << "Max path sum: " << maximumPath(2, mat) << " (expected 1009)\n";
    return 0;
}
