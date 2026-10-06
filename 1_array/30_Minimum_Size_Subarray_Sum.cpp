#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        size_t left = 0;
        int sum = 0, min_len = INT_MAX;
        for (size_t right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                min_len = min(min_len, static_cast<int>(right - left + 1));
                sum -= nums[left++];
            }
        }
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int ans = sol.minSubArrayLen(target, nums);
    cout << "Min subarray length for target " << target << ": " << ans << endl;
    assert(ans == 2);
    return 0;
}
