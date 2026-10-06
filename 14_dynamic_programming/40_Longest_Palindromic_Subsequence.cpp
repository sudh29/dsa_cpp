#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int longestPalinSubseq(const std::string& S) {
    int n = S.length();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) dp[i][i] = 1;

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (S[i] == S[j]) {
                dp[i][j] = 2 + (len == 2 ? 0 : dp[i + 1][j - 1]);
            } else {
                dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    std::string s = "bbabcbcab";
    std::cout << "LPS length of 'bbabcbcab': " << longestPalinSubseq(s) << " (expected 7)\n";
    return 0;
}
