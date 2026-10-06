#include <iostream>
#include <vector>
#include <algorithm>

int maxSumPairWithDifferenceLessThanK(std::vector<int>& arr, int N, int K) {
    std::sort(arr.begin(), arr.end());
    std::vector<int> dp(N, 0);

    for (int i = 1; i < N; ++i) {
        dp[i] = dp[i - 1];
        if (arr[i] - arr[i - 1] < K) {
            int prev = (i >= 2) ? dp[i - 2] : 0;
            dp[i] = std::max(dp[i], prev + arr[i] + arr[i - 1]);
        }
    }
    return dp[N - 1];
}

int main() {
    std::vector<int> arr = {3, 5, 10, 15, 17, 12, 9};
    int K = 4;
    std::cout << "Max sum pair diff < " << K << ": "
              << maxSumPairWithDifferenceLessThanK(arr, arr.size(), K) << " (expected 62)\n";
    return 0;
}
