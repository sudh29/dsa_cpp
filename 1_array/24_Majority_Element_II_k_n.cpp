#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <unordered_map>
#include <vector>

class Solution {
public:
    // Elements appearing more than n/k times
    std::vector<int> majorityElementK(std::span<const int> nums, int k) {
        if (k <= 0 || nums.empty()) return {};
        std::unordered_map<int, int> count;
        size_t n = nums.size();
        for (int v : nums) count[v]++;

        std::vector<int> res;
        for (const auto &[val, freq] : count) {
            if (static_cast<size_t>(freq) > n / static_cast<size_t>(k)) {
                res.push_back(val);
            }
        }
        std::sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {3, 1, 2, 2, 1, 2, 3, 3};
    // n = 8, k = 4 -> threshold = 8 / 4 = 2. Frequencies: 1:2, 2:3, 3:3. Elements > 2 are 2 and 3.
    auto res = sol.majorityElementK(nums, 4);
    std::vector<int> expected = {2, 3};
    assert(res == expected);

    std::vector<int> single = {5};
    auto resSingle = sol.majorityElementK(single, 2);
    std::vector<int> expSingle = {5};
    assert(resSingle == expSingle);

    std::cout << "1_array 24_Majority_Element_II_k_n: All tests passed.\n";
    return 0;
}
