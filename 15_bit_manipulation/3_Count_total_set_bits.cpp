#include <bit>
#include <cassert>
#include <iostream>

/**
 * Problem: Count Total Set Bits from 1 to N
 * Module: 15_bit_manipulation
 * Time Complexity: O(log N)
 * Space Complexity: O(log N) recursion depth
 *
 * Description:
 * Counts the total number of set bits (1s) across all integers in the range [1, N].
 */

class Solution {
private:
    [[nodiscard]] static constexpr int findLargestPowerOf2(int n) noexcept {
        if (n <= 0) return 0;
        return std::bit_width(static_cast<unsigned int>(n)) - 1;
    }

public:
    [[nodiscard]] constexpr int countSetBits(int n) noexcept {
        if (n <= 0) return 0;
        int x = findLargestPowerOf2(n);
        int bits_up_to_2_pow_x = (x > 0) ? (x * (1 << (x - 1))) : 0;
        int msb_from_2_pow_x_to_n = n - (1 << x) + 1;
        int rest = n - (1 << x);
        return bits_up_to_2_pow_x + msb_from_2_pow_x_to_n + countSetBits(rest);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Small numbers
    // 1(1) + 2(1) + 3(2) + 4(1) = 5
    assert(sol.countSetBits(4) == 5);

    // Test Case 2: 1 to 17 = 35 set bits
    assert(sol.countSetBits(17) == 35);

    // Test Case 3: Zero
    assert(sol.countSetBits(0) == 0);

    // Test Case 4: Single number 1
    assert(sol.countSetBits(1) == 1);

    // Test Case 5: 1 to 3 (all 2-bit combinations)
    // 1(1) + 2(1) + 3(2) = 4
    assert(sol.countSetBits(3) == 4);

    // Compile-time check
    static_assert(Solution{}.countSetBits(4) == 5);
    static_assert(Solution{}.countSetBits(17) == 35);
    static_assert(Solution{}.countSetBits(1) == 1);

    std::cout << "[PASS] 15_bit_manipulation/3_Count_total_set_bits: all tests passed!\n";
    return 0;
}
