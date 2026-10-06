#include <iostream>
#include <vector>
#include <algorithm>

long long maxSubArraySum(const std::vector<int>& arr) {
    long long max_so_far = arr[0];
    long long curr = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        curr = std::max(1LL * arr[i], curr + arr[i]);
        max_so_far = std::max(max_so_far, curr);
    }
    return max_so_far;
}

int main() {
    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "Max contiguous subarray sum: " << maxSubArraySum(arr) << " (expected 6)\n";
    return 0;
}
