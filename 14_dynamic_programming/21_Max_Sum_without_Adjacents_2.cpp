#include <iostream>
#include <vector>
#include <algorithm>

int findMaxSum(const std::vector<int>& arr, int n) {
    if (n == 0) return 0;
    if (n == 1) return arr[0];
    if (n == 2) return arr[0] + arr[1];
    if (n == 3) return std::max({arr[0] + arr[1], arr[1] + arr[2], arr[0] + arr[2]});

    std::vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = std::max({arr[0] + arr[1], arr[1] + arr[2], arr[0] + arr[2]});

    for (int i = 3; i < n; ++i) {
        dp[i] = std::max({dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i] + arr[i - 1]});
    }
    return dp[n - 1];
}

int main() {
    std::vector<int> arr = {100, 1000, 100, 1000, 1};
    std::cout << "Max sum without 3 adjacent: " << findMaxSum(arr, arr.size()) << " (expected 2101)\n";
    return 0;
}
