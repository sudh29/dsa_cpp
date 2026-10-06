#include <algorithm>
#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

class Solution {
public:
    int LongestRepeatingSubsequence(std::string_view str) {
        size_t n = str.length();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= n; ++j) {
                if (str[i - 1] == str[j - 1] && i != j) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};

int main() {
    Solution sol;
    assert(sol.LongestRepeatingSubsequence("axxzxy") == 2); // "xx"
    assert(sol.LongestRepeatingSubsequence("aab") == 1); // "a"
    assert(sol.LongestRepeatingSubsequence("abc") == 0);

    std::cout << "3_string 8_Find_Longest_Recurring_Subsequence_String: All tests passed.\n";
    return 0;
}
