#include <bit>
#include <cassert>
#include <cstdint>
#include <iostream>

/**
 * Problem: Find Position of the Only Set Bit
 * Module: 15_bit_manipulation
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 *
 * Description:
 * Given a number N having only one set bit, finds the 1-based position of the set bit.
 * If N does not have exactly one set bit, returns -1.
 */

class Solution {
public:
    [[nodiscard]] constexpr int findPosition(int64_t n) noexcept {
        if (n <= 0 || !std::has_single_bit(static_cast<uint64_t>(n))) {
            return -1;
        }
        // std::countr_zero gives 0-based trailing zeros; add 1 for 1-based index
        return std::countr_zero(static_cast<uint64_t>(n)) + 1;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Valid powers of two
    assert(sol.findPosition(1) == 1);     // 2^0 -> position 1
    assert(sol.findPosition(2) == 2);     // 2^1 -> position 2
    assert(sol.findPosition(16) == 5);    // 2^4 -> position 5
    assert(sol.findPosition(1024) == 11); // 2^10 -> position 11

    // Test Case 2: Numbers with multiple set bits
    assert(sol.findPosition(12) == -1);
    assert(sol.findPosition(7) == -1);
    assert(sol.findPosition(3) == -1);

    // Test Case 3: Zero and negative numbers
    assert(sol.findPosition(0) == -1);
    assert(sol.findPosition(-16) == -1);

    // Compile-time verification
    static_assert(Solution{}.findPosition(16) == 5);
    static_assert(Solution{}.findPosition(12) == -1);

    std::cout << "[PASS] 15_bit_manipulation/5_Find_position_of_the_only_set_bit: all tests passed!\n";
    return 0;
}
