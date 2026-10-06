#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

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
    std::vector<int> arr1 = {1, 5, 11, 5};
    assert(equalPartition(arr1.size(), arr1) == true);

    std::vector<int> arr2 = {1, 3, 5};
    assert(equalPartition(arr2.size(), arr2) == false);

    std::vector<int> arr3 = {2, 2};
    assert(equalPartition(arr3.size(), arr3) == true);

    std::cout << "7_Subset_Sum_Problem tests passed.\n";
    return 0;
}
