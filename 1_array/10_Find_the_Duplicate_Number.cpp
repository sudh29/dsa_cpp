#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    // Floyd's Tortoise and Hare Cycle Detection
    int findDuplicate(std::span<const int> nums) {
        assert(nums.size() >= 2);
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 3, 4, 2, 2};
    assert(sol.findDuplicate(nums1) == 2);

    std::vector<int> nums2 = {3, 1, 3, 4, 2};
    assert(sol.findDuplicate(nums2) == 3);

    std::cout << "1_array 10_Find_the_Duplicate_Number: All tests passed.\n";
    return 0;
}
