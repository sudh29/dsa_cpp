#include <cassert>
#include <cstdint>
#include <iostream>
#include <span>
#include <vector>

class Solution {
private:
    int64_t merge(std::span<int64_t> arr, size_t l, size_t m, size_t r) {
        int64_t ci = 0;
        size_t i = l;
        size_t j = m + 1;
        std::vector<int64_t> temp;
        temp.reserve(r - l + 1);

        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                ci += static_cast<int64_t>(m - i + 1);
            }
        }
        while (i <= m) temp.push_back(arr[i++]);
        while (j <= r) temp.push_back(arr[j++]);
        for (size_t p = 0; p < temp.size(); ++p) {
            arr[l + p] = temp[p];
        }
        return ci;
    }

    int64_t mergesort(std::span<int64_t> arr, size_t low, size_t high) {
        int64_t ci = 0;
        if (low < high) {
            size_t mid = low + (high - low) / 2;
            ci += mergesort(arr, low, mid);
            ci += mergesort(arr, mid + 1, high);
            ci += merge(arr, low, mid, high);
        }
        return ci;
    }

public:
    int64_t inversionCount(std::span<int64_t> arr) {
        if (arr.size() <= 1) return 0;
        return mergesort(arr, 0, arr.size() - 1);
    }
};

int main() {
    Solution sol;
    std::vector<int64_t> arr1 = {2, 4, 1, 3, 5};
    assert(sol.inversionCount(arr1) == 3);

    std::vector<int64_t> arr2 = {5, 4, 3, 2, 1};
    assert(sol.inversionCount(arr2) == 10);

    std::vector<int64_t> arr3 = {1, 2, 3, 4, 5};
    assert(sol.inversionCount(arr3) == 0);

    std::cout << "1_array 15_Count_Inversions: All tests passed.\n";
    return 0;
}
