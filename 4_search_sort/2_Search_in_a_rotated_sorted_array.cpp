#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    int search(std::span<const int> nums, int target) {
        int start = 0, end = static_cast<int>(nums.size()) - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return mid;

            if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    assert(sol.search(nums, 0) == 4);
    assert(sol.search(nums, 3) == -1);
    assert(sol.search(nums, 4) == 0);
    assert(sol.search(nums, 2) == 6);

    std::vector<int> single = {1};
    assert(sol.search(single, 1) == 0);
    assert(sol.search(single, 0) == -1);
    assert(sol.search({}, 5) == -1);

    std::cout << "2_Search_in_a_rotated_sorted_array tests passed.\n";
    return 0;
}
