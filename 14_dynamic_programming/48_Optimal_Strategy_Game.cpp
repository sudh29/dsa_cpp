#include <iostream>
#include <vector>
#include <algorithm>

long long optimalStrategyOfGame(int n, const std::vector<int>& arr) {
    std::vector<std::vector<long long>> dp(n, std::vector<long long>(n, 0));

    for (int i = 0; i < n; ++i) dp[i][i] = arr[i];
    for (int i = 0; i < n - 1; ++i) dp[i][i + 1] = std::max(arr[i], arr[i + 1]);

    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            long long take_i = arr[i] + std::min(dp[i + 2][j], dp[i + 1][j - 1]);
            long long take_j = arr[j] + std::min(dp[i + 1][j - 1], dp[i][j - 2]);
            dp[i][j] = std::max(take_i, take_j);
        }
    }
    return dp[0][n - 1];
}

int main() {
    std::vector<int> arr = {5, 3, 7, 10};
    std::cout << "Optimal game score: " << optimalStrategyOfGame(arr.size(), arr) << " (expected 15)\n";
    return 0;
}
