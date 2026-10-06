#include <bit>
#include <cassert>
#include <cstdint>
#include <iostream>

/**
 * Problem: Number of 1 Bits (Hamming Weight)
 * Module: 15_bit_manipulation
 * Time Complexity: O(k) where k is the number of set bits (Brian Kernighan) or O(1) via std::popcount
 * Space Complexity: O(1)
 *
 * Description:
 * Counts the number of set bits (1s) in the binary representation of an integer.
 */

class Solution {
public:
    // Classic Brian Kernighan bit trick
    [[nodiscard]] constexpr int setBitsKernighan(uint32_t n) noexcept {
        int count = 0;
        while (n > 0) {
            n &= (n - 1);
            ++count;
        }
        return count;
    }

    // Modern C++20 std::popcount implementation
    [[nodiscard]] constexpr int setBits(uint32_t n) noexcept {
        return std::popcount(n);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard values
    assert(sol.setBits(6) == 2);
    assert(sol.setBitsKernighan(6) == 2);

    assert(sol.setBits(13) == 3);
    assert(sol.setBitsKernighan(13) == 3);

    // Test Case 2: Zero
    assert(sol.setBits(0) == 0);
    assert(sol.setBitsKernighan(0) == 0);

    // Test Case 3: Power of 2 (single bit)
    assert(sol.setBits(1024) == 1);
    assert(sol.setBitsKernighan(1024) == 1);

    // Test Case 4: All bits set (32-bit max)
    assert(sol.setBits(0xFFFFFFFFU) == 32);
    assert(sol.setBitsKernighan(0xFFFFFFFFU) == 32);

    // Compile-time validation
    static_assert(Solution{}.setBits(7) == 3);
    static_assert(Solution{}.setBitsKernighan(7) == 3);

    std::cout << "[PASS] 15_bit_manipulation/0_Number_of_1_Bits: all tests passed!\n";
    return 0;
}
