#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(int K, int N, const std::vector<int>& A) {
    if (N <= 1 || K == 0) return 0;

    std::vector<std::vector<int>> dp(K + 1, std::vector<int>(N, 0));

    for (int t = 1; t <= K; ++t) {
        int max_diff = -A[0];
        for (int d = 1; d < N; ++d) {
            dp[t][d] = std::max(dp[t][d - 1], A[d] + max_diff);
            max_diff = std::max(max_diff, dp[t - 1][d] - A[d]);
        }
    }
    return dp[K][N - 1];
}

int main() {
    std::vector<int> A = {10, 22, 5, 75, 65, 80};
    int K = 2;
    std::cout << "Max profit with K=2: " << maxProfit(K, A.size(), A) << " (expected 87)\n";
    return 0;
}
