#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <span>
#include <utility>
#include <vector>

class Solution {
public:
    int64_t maxProduct(std::span<const int> arr) {
        if (arr.empty()) return 0;
        int64_t maxProd = arr[0];
        int64_t curMax = arr[0];
        int64_t curMin = arr[0];

        for (size_t i = 1; i < arr.size(); ++i) {
            int64_t val = arr[i];
            if (val < 0) {
                std::swap(curMax, curMin);
            }
            curMax = std::max(val, curMax * val);
            curMin = std::min(val, curMin * val);
            maxProd = std::max(maxProd, curMax);
        }
        return maxProd;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {6, -3, -10, 0, 2};
    assert(sol.maxProduct(arr1) == 180);

    std::vector<int> arr2 = {-2, 0, -1};
    assert(sol.maxProduct(arr2) == 0);

    std::vector<int> arr3 = {-2, 3, -4};
    assert(sol.maxProduct(arr3) == 24);

    std::cout << "1_array 22_Maximum_Product_Subarray: All tests passed.\n";
    return 0;
}
