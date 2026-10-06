#include <iostream>
#include <vector>
#include <numeric>

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
    return solve(arr, 0, 0, total_sum / 2);
}

int main() {
    std::vector<int> arr1 = {1, 5, 11, 5};
    std::cout << "Equal partition {1, 5, 11, 5}: " << (equalPartition(arr1.size(), arr1) ? "YES" : "NO") << "\n";

    std::vector<int> arr2 = {1, 3, 5};
    std::cout << "Equal partition {1, 3, 5}: " << (equalPartition(arr2.size(), arr2) ? "YES" : "NO") << "\n";
    return 0;
}
