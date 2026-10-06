#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

bool solve(const std::vector<int>& arr, size_t idx, int curr_sum, int target_sum) {
    if (curr_sum == target_sum) return true;
    if (curr_sum > target_sum || idx >= arr.size()) return false;

    if (solve(arr, idx + 1, curr_sum + arr[idx], target_sum)) return true;
    return solve(arr, idx + 1, curr_sum, target_sum);
}

bool equalPartition(int N, const std::vector<int>& arr) {
    (void)N;
    long long total_sum = 0;
    for (int x : arr) total_sum += x;
    if (total_sum % 2 != 0) return false;
    return solve(arr, 0, 0, static_cast<int>(total_sum / 2));
}

int main() {
    std::vector<int> arr1 = {1, 5, 11, 5};
    assert(equalPartition(static_cast<int>(arr1.size()), arr1) == true);

    std::vector<int> arr2 = {1, 3, 5};
    assert(equalPartition(static_cast<int>(arr2.size()), arr2) == false);

    std::vector<int> arr3 = {2, 2};
    assert(equalPartition(static_cast<int>(arr3.size()), arr3) == true);

    std::cout << "7_Partition_Equal_Subset_Sum tests passed.\n";
    return 0;
}
