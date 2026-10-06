#include <bit>
#include <cassert>
#include <cstdint>
#include <iostream>

/**
 * Problem: Bit Difference (Hamming Distance between Two Numbers)
 * Module: 15_bit_manipulation
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 *
 * Description:
 * Counts the number of bits needed to flip to convert integer a into integer b.
 */

class Solution {
public:
    [[nodiscard]] constexpr int countBitsFlip(uint32_t a, uint32_t b) noexcept {
        uint32_t xor_val = a ^ b;
        return std::popcount(xor_val);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case (10 = 01010, 20 = 10100 -> 4 flips)
    assert(sol.countBitsFlip(10, 20) == 4);

    // Test Case 2: Identical numbers
    assert(sol.countBitsFlip(42, 42) == 0);

    // Test Case 3: Complete inversion of 32 bits
    assert(sol.countBitsFlip(0x00000000U, 0xFFFFFFFFU) == 32);

    // Test Case 4: Alternating bit patterns
    assert(sol.countBitsFlip(0xAAAAAAAAU, 0x55555555U) == 32);

    // Test Case 5: Single bit difference
    assert(sol.countBitsFlip(7, 6) == 1);

    // Compile-time check
    static_assert(Solution{}.countBitsFlip(10, 20) == 4);

    std::cout << "[PASS] 15_bit_manipulation/2_Bit_Difference: all tests passed!\n";
    return 0;
}
