#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::span<const int> nums) {
        size_t left = 0;
        int sum = 0;
        int minLen = INT_MAX;
        for (size_t right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum >= target) {
                minLen = std::min(minLen, static_cast<int>(right - left + 1));
                sum -= nums[left++];
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    assert(sol.minSubArrayLen(7, nums1) == 2); // [4, 3]

    std::vector<int> nums2 = {1, 4, 4};
    assert(sol.minSubArrayLen(4, nums2) == 1);

    std::vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    assert(sol.minSubArrayLen(11, nums3) == 0);

    std::cout << "1_array 30_Minimum_Size_Subarray_Sum: All tests passed.\n";
    return 0;
}
