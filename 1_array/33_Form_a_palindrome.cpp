#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Solution {
public:
    // Minimum insertions to form a palindrome = n - LPS(s)
    int countMin(std::string_view str) {
        size_t n = str.length();
        if (n <= 1) return 0;
        std::string rev(str.rbegin(), str.rend());

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= n; ++j) {
                if (str[i - 1] == rev[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return static_cast<int>(n) - dp[n][n];
    }
};

int main() {
    Solution sol;
    assert(sol.countMin("abcd") == 3);
    assert(sol.countMin("aba") == 0);
    assert(sol.countMin("geeks") == 3);
    assert(sol.countMin("a") == 0);
    assert(sol.countMin("") == 0);

    std::cout << "1_array 33_Form_a_palindrome: All tests passed.\n";
    return 0;
}
