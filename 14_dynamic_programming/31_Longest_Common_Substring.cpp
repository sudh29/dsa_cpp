#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int longestCommonSubstr(const std::string& str1, const std::string& str2) {
    int n = str1.length();
    int m = str2.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    int max_len = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_len = std::max(max_len, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return max_len;
}

int main() {
    std::string s1 = "ABCDGH";
    std::string s2 = "ACDGHR";
    std::cout << "Longest common substring: " << longestCommonSubstr(s1, s2) << " (expected 4)\n";
    return 0;
}
