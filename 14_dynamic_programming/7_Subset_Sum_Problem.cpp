#include <iostream>
#include <vector>
#include <numeric>

bool equalPartition(int N, const std::vector<int>& arr) {
    (void)N;
    long long total = 0;
    for (int x : arr) total += x;
    if (total % 2 != 0) return false;

    int target = total / 2;
    std::vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : arr) {
        for (int j = target; j >= num; --j) {
            if (dp[j - num]) dp[j] = true;
        }
    }
    return dp[target];
}

int main() {
    std::vector<int> arr = {1, 5, 11, 5};
    std::cout << "Can partition {1, 5, 11, 5}: " << (equalPartition(arr.size(), arr) ? "YES" : "NO") << "\n";
    return 0;
}
