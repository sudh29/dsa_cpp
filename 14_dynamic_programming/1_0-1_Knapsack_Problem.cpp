#include <iostream>
#include <vector>
#include <algorithm>

int knapSack(int W, const std::vector<int>& wt, const std::vector<int>& val, int n) {
    std::vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int w = W; w >= wt[i]; --w) {
            dp[w] = std::max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W];
}

int main() {
    std::vector<int> val = {60, 100, 120};
    std::vector<int> wt = {10, 20, 30};
    int W = 50;
    std::cout << "Max 0-1 Knapsack value: " << knapSack(W, wt, val, val.size()) << " (expected 220)\n";
    return 0;
}
