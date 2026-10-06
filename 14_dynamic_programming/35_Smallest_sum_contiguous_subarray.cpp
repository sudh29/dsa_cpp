#include <iostream>
#include <vector>
#include <algorithm>

int smallestSumSubarray(const std::vector<int>& arr, int n) {
    int min_so_far = arr[0];
    int curr = arr[0];

    for (int i = 1; i < n; ++i) {
        curr = std::min(arr[i], curr + arr[i]);
        min_so_far = std::min(min_so_far, curr);
    }
    return min_so_far;
}

int main() {
    std::vector<int> arr = {3, -4, 2, -3, -1, 7, -5};
    std::cout << "Smallest contiguous subarray sum: " << smallestSumSubarray(arr, arr.size()) << " (expected -6)\n";
    return 0;
}
