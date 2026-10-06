#include <iostream>
#include <vector>
#include <algorithm>

int knapSackUnbounded(int N, int W, const std::vector<int>& val, const std::vector<int>& wt) {
    std::vector<int> dp(W + 1, 0);

    for (int i = 0; i < N; ++i) {
        for (int w = wt[i]; w <= W; ++w) {
            dp[w] = std::max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W];
}

int main() {
    std::vector<int> val = {1, 4, 5, 7};
    std::vector<int> wt = {1, 3, 4, 5};
    int W = 8;
    std::cout << "Unbounded knapsack max val: " << knapSackUnbounded(val.size(), W, val, wt) << " (expected 11)\n";
    return 0;
}
