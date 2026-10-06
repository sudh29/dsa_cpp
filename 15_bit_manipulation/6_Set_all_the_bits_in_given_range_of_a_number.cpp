#include <cassert>
#include <cstdint>
#include <iostream>

/**
 * Problem: Set All Bits in Given Range [L, R] of a Number
 * Module: 15_bit_manipulation
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 *
 * Description:
 * Sets all bits from 1-based position L to position R (inclusive) in number N.
 */

class Solution {
public:
    [[nodiscard]] constexpr uint32_t setAllRangeBits(uint32_t n, int l, int r) noexcept {
        if (l > r || l < 1 || r > 32) return n;
        uint32_t mask = 0;
        if (r == 32) {
            mask = ~0U;
        } else {
            mask = (1U << r) - 1U;
        }
        mask ^= ((1U << (l - 1)) - 1U);
        return n | mask;
    }
};

int main() {
    Solution sol;

    // Test Case 1: N = 17 (10001), L = 2, R = 3 -> bits 2 and 3 set -> 10111 (23)
    assert(sol.setAllRangeBits(17, 2, 3) == 23);

    // Test Case 2: N = 8 (1000), L = 1, R = 2 -> 1011 (11)
    assert(sol.setAllRangeBits(8, 1, 2) == 11);

    // Test Case 3: N = 0, L = 1, R = 4 -> 1111 (15)
    assert(sol.setAllRangeBits(0, 1, 4) == 15);

    // Test Case 4: Bits already set
    assert(sol.setAllRangeBits(15, 1, 4) == 15);

    // Test Case 5: Single bit range L == R
    assert(sol.setAllRangeBits(0, 3, 3) == 4);

    // Compile-time check
    static_assert(Solution{}.setAllRangeBits(17, 2, 3) == 23);

    std::cout << "[PASS] 15_bit_manipulation/6_Set_all_the_bits_in_given_range_of_a_number: all tests passed!\n";
    return 0;
}
