#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Non Repeating Numbers (Two Unique Numbers in Array of Pairs)
 * Module: 15_bit_manipulation
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Given an array where every element appears exactly twice except two unique elements,
 * finds those two unique elements in sorted order using XOR partitioning.
 */

class Solution {
public:
    [[nodiscard]] std::vector<int> singleNumber(std::span<const int> nums) {
        int xor_all = 0;
        for (int v : nums) {
            xor_all ^= v;
        }

        // Isolate lowest set bit using unsigned cast to prevent signed overflow UB on INT_MIN
        unsigned int u_xor = static_cast<unsigned int>(xor_all);
        unsigned int rightmost = u_xor & (~u_xor + 1U);

        int a = 0;
        int b = 0;
        for (int v : nums) {
            if (static_cast<unsigned int>(v) & rightmost) {
                a ^= v;
            } else {
                b ^= v;
            }
        }

        if (a > b) {
            std::swap(a, b);
        }
        return {a, b};
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard input
    {
        std::vector<int> nums = {1, 2, 3, 2, 1, 4};
        auto res = sol.singleNumber(nums);
        assert(res == (std::vector<int>{3, 4}));
    }

    // Test Case 2: Only the two unique numbers
    {
        std::vector<int> nums = {10, 20};
        auto res = sol.singleNumber(nums);
        assert(res == (std::vector<int>{10, 20}));
    }

    // Test Case 3: Already sorted output
    {
        std::vector<int> nums = {2, 1, 3, 2};
        auto res = sol.singleNumber(nums);
        assert(res == (std::vector<int>{1, 3}));
    }

    // Test Case 4: Negative numbers
    {
        std::vector<int> nums = {-5, 4, -5, 7};
        auto res = sol.singleNumber(nums);
        assert(res == (std::vector<int>{4, 7}));
    }

    std::cout << "[PASS] 15_bit_manipulation/1_Non_Repeating_Numbers: all tests passed!\n";
    return 0;
}
