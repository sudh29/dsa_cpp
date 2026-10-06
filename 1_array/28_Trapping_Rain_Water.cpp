#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    int64_t trappingWater(std::span<const int> arr) {
        if (arr.size() <= 2) return 0;
        int left = 0;
        int right = static_cast<int>(arr.size()) - 1;
        int maxLeft = 0;
        int maxRight = 0;
        int64_t water = 0;

        while (left <= right) {
            if (arr[left] <= arr[right]) {
                if (arr[left] >= maxLeft) maxLeft = arr[left];
                else water += (maxLeft - arr[left]);
                left++;
            } else {
                if (arr[right] >= maxRight) maxRight = arr[right];
                else water += (maxRight - arr[right]);
                right--;
            }
        }
        return water;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {3, 0, 0, 2, 0, 4};
    assert(sol.trappingWater(arr1) == 10);

    std::vector<int> arr2 = {7, 4, 0, 9};
    assert(sol.trappingWater(arr2) == 10);

    std::vector<int> arr3 = {6, 9, 9};
    assert(sol.trappingWater(arr3) == 0);

    std::cout << "1_array 28_Trapping_Rain_Water: All tests passed.\n";
    return 0;
}
