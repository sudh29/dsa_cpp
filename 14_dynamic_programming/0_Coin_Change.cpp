#include <iostream>
#include <vector>

long long countWays(const std::vector<int>& coins, int sum) {
    std::vector<long long> dp(sum + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int amount = coin; amount <= sum; ++amount) {
            dp[amount] += dp[amount - coin];
        }
    }
    return dp[sum];
}

int main() {
    std::vector<int> coins = {1, 2, 3};
    int sum = 4;
    std::cout << "Ways to make change for 4: " << countWays(coins, sum) << " (expected 4)\n";
    return 0;
}
