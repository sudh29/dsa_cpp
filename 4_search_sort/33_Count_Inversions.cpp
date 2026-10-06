#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    long long merge(std::vector<long long>& arr, size_t l, size_t m, size_t r) {
        long long ci = 0;
        size_t i = l, j = m + 1, k = 0;
        std::vector<long long> temp(r - l + 1);

        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                ci += static_cast<long long>(m - i + 1);
            }
        }
        while (i <= m) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];
        for (size_t p = 0; p < k; p++) arr[l + p] = temp[p];
        return ci;
    }

    long long mergesort(std::vector<long long>& arr, size_t low, size_t high) {
        long long ci = 0;
        if (low < high) {
            size_t mid = low + (high - low) / 2;
            ci += mergesort(arr, low, mid);
            ci += mergesort(arr, mid + 1, high);
            ci += merge(arr, low, mid, high);
        }
        return ci;
    }

    long long inversionCount(std::vector<long long> arr) {
        if (arr.empty()) return 0;
        return mergesort(arr, 0, arr.size() - 1);
    }
};

int main() {
    Solution sol;
    std::vector<long long> arr1 = {2, 4, 1, 3, 5};
    assert(sol.inversionCount(arr1) == 3);

    std::vector<long long> arr2 = {10, 10, 10};
    assert(sol.inversionCount(arr2) == 0);

    std::vector<long long> arr3 = {5, 4, 3, 2, 1};
    assert(sol.inversionCount(arr3) == 10);

    assert(sol.inversionCount({}) == 0);

    std::cout << "33_Count_Inversions tests passed.\n";
    return 0;
}
