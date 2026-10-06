#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

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
    int n = a.size();
    if (k == 1) return true;
    if (n < k) return false;

    long long total_sum = 0;
    for (int x : a) total_sum += x;
    if (total_sum % k != 0) return false;

    int target_sum = total_sum / k;
    std::vector<bool> visited(n, false);
    return solve(a, n, k, 0, 0, visited, target_sum, n - 1);
}

int main() {
    std::vector<int> a1 = {2, 1, 4, 5, 6};
    int k1 = 3;
    std::cout << "Can partition into 3 subsets: " << (isKPartitionPossible(a1, k1) ? "YES (1)" : "NO (0)") << "\n";

    std::vector<int> a2 = {2, 1, 5, 5, 6};
    int k2 = 3;
    std::cout << "Can partition into 3 subsets: " << (isKPartitionPossible(a2, k2) ? "YES (1)" : "NO (0)") << "\n";
    return 0;
}
