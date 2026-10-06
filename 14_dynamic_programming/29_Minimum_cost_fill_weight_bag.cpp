#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int minimumCost(int n, int w, const std::vector<int>& cost) {
    std::vector<int> dp(w + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        if (cost[i - 1] != -1) {
            for (int j = i; j <= w; ++j) {
                if (dp[j - i] != INT_MAX) {
                    dp[j] = std::min(dp[j], dp[j - i] + cost[i - 1]);
                }
            }
        }
    }
    return dp[w] == INT_MAX ? -1 : dp[w];
}

int main() {
    std::vector<int> cost = {20, 10, 4, 50, 100};
    int w = 5;
    std::cout << "Minimum cost to fill bag: " << minimumCost(cost.size(), w, cost) << " (expected 14)\n";
    return 0;
}
