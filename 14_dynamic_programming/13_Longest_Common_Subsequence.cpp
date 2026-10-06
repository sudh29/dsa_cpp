#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int lcs(int x, int y, const std::string& s1, const std::string& s2) {
    (void)x; (void)y;
    int n = s1.length();
    int m = s2.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    std::string s1 = "ABCDGH";
    std::string s2 = "AEDFHR";
    std::cout << "LCS length: " << lcs(s1.length(), s2.length(), s1, s2) << " (expected 3)\n";
    return 0;
}
