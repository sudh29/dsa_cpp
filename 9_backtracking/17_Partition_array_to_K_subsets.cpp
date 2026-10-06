#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

bool solve(const std::vector<int>& a, int n, int k, int curr_sum, int count,
           std::vector<bool>& visited, int target_sum, int idx) {
    if (curr_sum == target_sum) {
        if (count == k - 2) return true;
        return solve(a, n, k, 0, count + 1, visited, target_sum, n - 1);
    }

    for (int i = idx; i >= 0; --i) {
        if (visited[i] || curr_sum + a[i] > target_sum) continue;
        visited[i] = true;
        if (solve(a, n, k, curr_sum + a[i], count, visited, target_sum, i - 1)) {
            return true;
        }
        visited[i] = false;
    }
    return false;
}

bool isKPartitionPossible(std::vector<int>& a, int k) {
    int n = static_cast<int>(a.size());
    if (k == 1) return true;
    if (n < k) return false;

    long long total_sum = 0;
    for (int x : a) total_sum += x;
    if (total_sum % k != 0) return false;

    int target_sum = static_cast<int>(total_sum / k);
    std::vector<bool> visited(n, false);
    return solve(a, n, k, 0, 0, visited, target_sum, n - 1);
}

int main() {
    std::vector<int> a1 = {2, 1, 4, 5, 6};
    assert(isKPartitionPossible(a1, 3) == true);

    std::vector<int> a2 = {2, 1, 5, 5, 6};
    assert(isKPartitionPossible(a2, 3) == false);

    std::vector<int> a3 = {1, 1, 1, 1};
    assert(isKPartitionPossible(a3, 4) == true);

    std::cout << "17_Partition_array_to_K_subsets tests passed.\n";
    return 0;
}
