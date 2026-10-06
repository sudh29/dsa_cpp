#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <span>
#include <vector>

class Solution {
private:
    size_t nextGap(size_t gap) {
        if (gap <= 1) return 0;
        return (gap / 2) + (gap % 2);
    }

public:
    void merge(std::span<int64_t> arr1, std::span<int64_t> arr2) {
        size_t n = arr1.size();
        size_t m = arr2.size();
        size_t gap = nextGap(n + m);

        while (gap > 0) {
            size_t i = 0;
            size_t j = gap;
            while (j < (n + m)) {
                if (j < n && arr1[i] > arr1[j]) {
                    std::swap(arr1[i], arr1[j]);
                } else if (i < n && j >= n && arr1[i] > arr2[j - n]) {
                    std::swap(arr1[i], arr2[j - n]);
                } else if (i >= n && j >= n && arr2[i - n] > arr2[j - n]) {
                    std::swap(arr2[i - n], arr2[j - n]);
                }
                i++;
                j++;
            }
            gap = nextGap(gap);
        }
    }
};

int main() {
    Solution sol;
    std::vector<int64_t> arr1 = {1, 3, 5, 7};
    std::vector<int64_t> arr2 = {0, 2, 6, 8, 9};
    sol.merge(arr1, arr2);

    std::vector<int64_t> expected1 = {0, 1, 2, 3};
    std::vector<int64_t> expected2 = {5, 6, 7, 8, 9};
    assert(arr1 == expected1);
    assert(arr2 == expected2);

    std::cout << "1_array 11_Merge_Without_Extra_Space: All tests passed.\n";
    return 0;
}
