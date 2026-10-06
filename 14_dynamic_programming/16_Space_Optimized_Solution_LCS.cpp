#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int lcsSpaceOptimized(const std::string& X, const std::string& Y) {
    int m = X.length();
    int n = Y.length();
    std::vector<std::vector<int>> dp(2, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        int curr = i % 2;
        int prev = 1 - curr;
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[curr][j] = dp[prev][j - 1] + 1;
            } else {
                dp[curr][j] = std::max(dp[prev][j], dp[curr][j - 1]);
            }
        }
    }
    return dp[m % 2][n];
}

int main() {
    std::string s1 = "AGGTAB";
    std::string s2 = "GXTXAYB";
    std::cout << "Space-optimized LCS: " << lcsSpaceOptimized(s1, s2) << " (expected 4)\n";
    return 0;
}
