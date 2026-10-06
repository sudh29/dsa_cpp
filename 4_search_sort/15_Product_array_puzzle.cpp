#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    std::vector<long long> productExceptSelf(std::span<const long long> nums) {
        size_t n = nums.size();
        if (n == 0) return {};
        std::vector<long long> res(n, 1);
        long long left = 1;
        for (size_t i = 0; i < n; i++) {
            res[i] = left;
            left *= nums[i];
        }
        long long right = 1;
        for (size_t i = n; i > 0; i--) {
            res[i - 1] *= right;
            right *= nums[i - 1];
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<long long> nums1 = {10, 3, 5, 6, 2};
    auto res1 = sol.productExceptSelf(nums1);
    std::vector<long long> expected1 = {180, 600, 360, 300, 900};
    assert(res1 == expected1);

    std::vector<long long> nums2 = {12, 0};
    auto res2 = sol.productExceptSelf(nums2);
    std::vector<long long> expected2 = {0, 12};
    assert(res2 == expected2);

    assert(sol.productExceptSelf({}).empty());

    std::cout << "15_Product_array_puzzle tests passed.\n";
    return 0;
}
