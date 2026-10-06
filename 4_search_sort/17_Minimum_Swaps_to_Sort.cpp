#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

class Solution {
public:
    int minSwaps(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        std::vector<std::pair<int, int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {nums[i], i};
        std::sort(v.begin(), v.end());

        std::vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || v[i].second == i) continue;

            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = v[j].second;
                cycle_size++;
            }
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        return swaps;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {2, 8, 5, 4};
    assert(sol.minSwaps(nums1) == 1);

    std::vector<int> nums2 = {10, 19, 6, 3, 5};
    assert(sol.minSwaps(nums2) == 2);

    std::vector<int> nums3 = {1, 2, 3};
    assert(sol.minSwaps(nums3) == 0);

    std::cout << "17_Minimum_Swaps_to_Sort tests passed.\n";
    return 0;
}
