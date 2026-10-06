#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    void nextPermutation(std::span<int> nums) {
        if (nums.size() <= 1) return;
        int n = static_cast<int>(nums.size());
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            std::swap(nums[i], nums[j]);
        }
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 2, 3};
    sol.nextPermutation(nums1);
    std::vector<int> exp1 = {1, 3, 2};
    assert(nums1 == exp1);

    std::vector<int> nums2 = {3, 2, 1};
    sol.nextPermutation(nums2);
    std::vector<int> exp2 = {1, 2, 3};
    assert(nums2 == exp2);

    std::vector<int> nums3 = {1, 1, 5};
    sol.nextPermutation(nums3);
    std::vector<int> exp3 = {1, 5, 1};
    assert(nums3 == exp3);

    std::cout << "1_array 14_Next_Permutation: All tests passed.\n";
    return 0;
}
