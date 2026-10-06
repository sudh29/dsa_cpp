#include <algorithm>
#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

class Solution {
public:
    int lcs(int x, int y, std::string_view s1, std::string_view s2) {
        std::vector<std::vector<int>> dp(x + 1, std::vector<int>(y + 1, 0));
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[x][y];
    }
};

int main() {
    Solution sol;
    std::string_view s1 = "ABCDGH", s2 = "AEDFHR";
    assert(sol.lcs(static_cast<int>(s1.length()), static_cast<int>(s2.length()), s1, s2) == 3);

    std::string_view s3 = "ABC", s4 = "AC";
    assert(sol.lcs(static_cast<int>(s3.length()), static_cast<int>(s4.length()), s3, s4) == 2);

    std::string_view s5 = "XYZ", s6 = "ABC";
    assert(sol.lcs(static_cast<int>(s5.length()), static_cast<int>(s6.length()), s5, s6) == 0);

    std::cout << "30_Longest_Common_Subsequence tests passed.\n";
    return 0;
}
