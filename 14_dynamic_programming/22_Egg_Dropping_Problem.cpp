#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int eggDrop(int N, int K) {
    if (N == 1) return K;
    if (K == 0 || K == 1) return K;

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(K + 1, 0));

    for (int i = 1; i <= N; ++i) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }
    for (int j = 1; j <= K; ++j) {
        dp[1][j] = j;
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 2; j <= K; ++j) {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; ++x) {
                int res = 1 + std::max(dp[i - 1][x - 1], dp[i][j - x]);
                dp[i][j] = std::min(dp[i][j], res);
            }
        }
    }
    return dp[N][K];
}

int main() {
    std::cout << "Egg drop N=2, K=10: " << eggDrop(2, 10) << " (expected 4)\n";
    std::cout << "Egg drop N=1, K=2: " << eggDrop(1, 2) << " (expected 2)\n";
    return 0;
}
