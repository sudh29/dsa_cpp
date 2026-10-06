#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

class Solution {
public:
    long long int countPS(std::string_view str) {
        int n = static_cast<int>(str.length());
        if (n == 0) return 0;
        constexpr long long int MOD = 1e9 + 7;
        std::vector<std::vector<long long int>> dp(n, std::vector<long long int>(n, 0));

        for (int i = 0; i < n; i++) dp[i][i] = 1;

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i <= n - L; i++) {
                int j = i + L - 1;
                if (str[i] == str[j]) {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
                } else {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution sol;
    assert(sol.countPS("abcd") == 4);
    assert(sol.countPS("aab") == 4);
    assert(sol.countPS("aaaa") == 15);
    assert(sol.countPS("a") == 1);
    assert(sol.countPS("") == 0);

    std::cout << "21_Count_Palindromic_Subsequences tests passed.\n";
    return 0;
}
