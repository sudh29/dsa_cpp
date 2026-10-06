#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

int minSwap(std::span<const int> arr, int k) {
    size_t n = arr.size();
    if (n <= 1) return 0;

    size_t good = 0;
    for (int val : arr) {
        if (val <= k) good++;
    }
    if (good <= 1) return 0;

    int bad = 0;
    for (size_t i = 0; i < good; ++i) {
        if (arr[i] > k) bad++;
    }

    int ans = bad;
    for (size_t i = 0, j = good; j < n; ++i, ++j) {
        if (arr[i] > k) bad--;
        if (arr[j] > k) bad++;
        ans = std::min(ans, bad);
    }
    return ans;
}

int main() {
    std::vector<int> arr1 = {2, 1, 5, 6, 3};
    assert(minSwap(arr1, 3) == 1);

    std::vector<int> arr2 = {2, 7, 9, 5, 8, 7, 4};
    assert(minSwap(arr2, 6) == 2);

    std::vector<int> arr3 = {1, 2, 3};
    assert(minSwap(arr3, 5) == 0);

    std::cout << "1_array 32_Minimum_swaps_and_K_together: All tests passed.\n";
    return 0;
}
