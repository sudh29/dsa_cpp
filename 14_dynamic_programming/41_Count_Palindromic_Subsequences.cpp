#include <iostream>
#include <string>
#include <vector>

long long countPS(const std::string& str) {
    int n = str.length();
    const long long MOD = 1000000007;
    std::vector<std::vector<long long>> dp(n, std::vector<long long>(n, 0));

    for (int i = 0; i < n; ++i) dp[i][i] = 1;

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (str[i] == str[j]) {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
            } else {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    std::string s = "abcd";
    std::cout << "Count PS of 'abcd': " << countPS(s) << " (expected 4)\n";
    std::string s2 = "aab";
    std::cout << "Count PS of 'aab': " << countPS(s2) << " (expected 4)\n";
    return 0;
}
