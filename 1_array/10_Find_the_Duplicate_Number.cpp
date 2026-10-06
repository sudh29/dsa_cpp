#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Floyd's Tortoise and Hare Cycle Detection
    int findDuplicate(vector<int>& nums) {
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
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << "Duplicate number: " << sol.findDuplicate(nums) << endl;
    return 0;
}
