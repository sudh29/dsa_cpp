#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

long long maxSum(std::vector<int>& arr, int n) {
    std::sort(arr.begin(), arr.end());
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += std::abs(arr[i] - arr[n - 1 - i]);
    }
    return res;
}

int main() {
    std::vector<int> arr1 = {4, 2, 1, 8};
    assert(maxSum(arr1, static_cast<int>(arr1.size())) == 18);

    std::vector<int> arr2 = {1, 2};
    assert(maxSum(arr2, static_cast<int>(arr2.size())) == 2);

    std::cout << "18_Maximize_sum_consecutive_differences_circular_array tests passed.\n";
    return 0;
}
