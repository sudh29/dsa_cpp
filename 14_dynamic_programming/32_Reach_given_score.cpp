#include <iostream>
#include <vector>

long long countWays(int n) {
    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    int moves[] = {3, 5, 10};

    for (int move : moves) {
        for (int i = move; i <= n; ++i) {
            dp[i] += dp[i - move];
        }
    }
    return dp[n];
}

int main() {
    std::cout << "Ways to reach 20: " << countWays(20) << " (expected 4)\n";
    std::cout << "Ways to reach 13: " << countWays(13) << " (expected 2)\n";
    return 0;
}
