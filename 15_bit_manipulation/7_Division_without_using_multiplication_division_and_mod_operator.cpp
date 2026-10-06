#include <cassert>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>

/**
 * Problem: Division Without Using Multiplication, Division, and Mod Operators
 * Module: 15_bit_manipulation
 * Time Complexity: O(log(dividend))
 * Space Complexity: O(1)
 *
 * Description:
 * Divides two integers using bitwise subtraction and shift operations,
 * properly handling signs and 64-bit integer limits.
 */

class Solution {
public:
    [[nodiscard]] int64_t divide(int64_t dividend, int64_t divisor) noexcept {
        if (divisor == 0) return INT64_MAX;
        if (dividend == 0) return 0;

        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        uint64_t dvd = (dividend < 0) ? static_cast<uint64_t>(-dividend) : static_cast<uint64_t>(dividend);
        uint64_t dvs = (divisor < 0) ? static_cast<uint64_t>(-divisor) : static_cast<uint64_t>(divisor);
        uint64_t quotient = 0;

        for (int i = 62; i >= 0; --i) {
            if ((dvd >> i) >= dvs) {
                dvd -= (dvs << i);
                quotient += (1ULL << i);
            }
        }

        return (sign < 0) ? -static_cast<int64_t>(quotient) : static_cast<int64_t>(quotient);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard positive division
    assert(sol.divide(10, 3) == 3);

    // Test Case 2: Negative numbers
    assert(sol.divide(43, -8) == -5);
    assert(sol.divide(-43, 8) == -5);
    assert(sol.divide(-43, -8) == 5);

    // Test Case 3: Large 64-bit dividend
    assert(sol.divide(1000000000000LL, 2LL) == 500000000000LL);

    // Test Case 4: Equal numbers and divisor = 1
    assert(sol.divide(100, 1) == 100);
    assert(sol.divide(100, 100) == 1);

    // Test Case 5: Divisor > Dividend
    assert(sol.divide(3, 10) == 0);

    // Test Case 6: Dividend = 0
    assert(sol.divide(0, 5) == 0);

    std::cout << "[PASS] 15_bit_manipulation/7_Division_without_using_multiplication_division_and_mod_operator: all tests passed!\n";
    return 0;
}
