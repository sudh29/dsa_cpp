#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int longestRepeatedSubsequence(const std::string& str) {
    int n = str.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str[i - 1] == str[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int main() {
    std::string s = "axxxxy";
    std::cout << "LRS length of 'axxxxy': " << longestRepeatedSubsequence(s) << " (expected 2)\n";
    return 0;
}
