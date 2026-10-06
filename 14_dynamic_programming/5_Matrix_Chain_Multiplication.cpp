#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int matrixMultiplication(int N, const std::vector<int>& arr) {
    std::vector<std::vector<int>> dp(N, std::vector<int>(N, 0));

    for (int l = 2; l < N; ++l) {
        for (int i = 1; i < N - l + 1; ++i) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][N - 1];
}

int main() {
    std::vector<int> arr = {40, 20, 30, 10, 30};
    std::cout << "Min matrix mult operations: " << matrixMultiplication(arr.size(), arr) << " (expected 26000)\n";
    return 0;
}
