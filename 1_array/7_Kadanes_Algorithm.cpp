#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdint>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    int64_t maxSubarraySum(std::span<const int> arr) {
        if (arr.empty()) return 0;
        int64_t maxSoFar = LLONG_MIN;
        int64_t currentMax = 0;
        for (int val : arr) {
            currentMax += val;
            if (maxSoFar < currentMax) maxSoFar = currentMax;
            if (currentMax < 0) currentMax = 0;
        }
        return maxSoFar;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {1, 2, 3, -2, 5};
    assert(sol.maxSubarraySum(arr1) == 9);

    std::vector<int> arr2 = {-1, -2, -3, -4};
    assert(sol.maxSubarraySum(arr2) == -1);

    std::cout << "1_array 7_Kadanes_Algorithm: All tests passed.\n";
    return 0;
}
