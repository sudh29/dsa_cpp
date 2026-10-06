#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int longestSubseq(int n, const std::vector<int>& a) {
    std::vector<int> dp(n, 1);
    int max_len = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (std::abs(a[i] - a[j]) == 1) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        max_len = std::max(max_len, dp[i]);
    }
    return max_len;
}

int main() {
    std::vector<int> a = {10, 9, 4, 5, 4, 8, 6};
    std::cout << "Longest subsequence diff 1: " << longestSubseq(a.size(), a) << " (expected 3)\n";
    return 0;
}
