#include <bit>
#include <cassert>
#include <cstdint>
#include <iostream>

/**
 * Problem: Check If Number is Power of Two
 * Module: 15_bit_manipulation
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 *
 * Description:
 * Determines if a given integer n is a power of two using bitwise operators
 * and modern C++20 std::has_single_bit.
 */

class Solution {
public:
    // Classic bitwise trick: n & (n - 1) == 0 for n > 0
    [[nodiscard]] constexpr bool isPowerOfTwoBitwise(int64_t n) noexcept {
        return (n > 0) && ((n & (n - 1)) == 0);
    }

    // Modern C++20 standard library concept
    [[nodiscard]] constexpr bool isPowerOfTwo(uint64_t n) noexcept {
        return std::has_single_bit(n);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Powers of 2
    assert(sol.isPowerOfTwo(1) == true);
    assert(sol.isPowerOfTwo(2) == true);
    assert(sol.isPowerOfTwo(16) == true);
    assert(sol.isPowerOfTwo(1024) == true);
    assert(sol.isPowerOfTwo(1ULL << 40) == true);

    assert(sol.isPowerOfTwoBitwise(1) == true);
    assert(sol.isPowerOfTwoBitwise(16) == true);
    assert(sol.isPowerOfTwoBitwise(1024) == true);

    // Test Case 2: Non-powers of 2
    assert(sol.isPowerOfTwo(0) == false);
    assert(sol.isPowerOfTwo(3) == false);
    assert(sol.isPowerOfTwo(18) == false);
    assert(sol.isPowerOfTwo(100) == false);

    assert(sol.isPowerOfTwoBitwise(0) == false);
    assert(sol.isPowerOfTwoBitwise(-16) == false);
    assert(sol.isPowerOfTwoBitwise(18) == false);

    // Compile-time checks
    static_assert(Solution{}.isPowerOfTwo(64));
    static_assert(!Solution{}.isPowerOfTwo(65));
    static_assert(Solution{}.isPowerOfTwoBitwise(64));

    std::cout << "[PASS] 15_bit_manipulation/4_Is_power_of_two: all tests passed!\n";
    return 0;
}
