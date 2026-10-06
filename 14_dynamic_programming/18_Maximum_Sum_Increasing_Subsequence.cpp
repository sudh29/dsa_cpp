#include <iostream>
#include <vector>
#include <algorithm>

int maxSumIS(const std::vector<int>& arr, int n) {
    std::vector<int> dp = arr;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                dp[i] = std::max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    int max_sum = 0;
    for (int x : dp) max_sum = std::max(max_sum, x);
    return max_sum;
}

int main() {
    std::vector<int> arr = {1, 101, 2, 3, 100, 4, 5};
    std::cout << "Max Sum Increasing Subsequence: " << maxSumIS(arr, arr.size()) << " (expected 106)\n";
    return 0;
}
