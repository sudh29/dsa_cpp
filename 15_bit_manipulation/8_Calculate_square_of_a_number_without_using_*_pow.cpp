#include <cassert>
#include <cstdint>
#include <iostream>

/**
 * Problem: Calculate Square of a Number Without Using * or Pow
 * Module: 15_bit_manipulation
 * Time Complexity: O(log N)
 * Space Complexity: O(log N) recursion depth
 *
 * Description:
 * Computes n^2 using bit shifts and recursion based on:
 *   If n is even: (2x)^2 = 4x^2 = (square(x) << 2)
 *   If n is odd:  (2x + 1)^2 = 4x^2 + 4x + 1 = ((square(x) + x) << 2) + 1
 */

constexpr int64_t square(int64_t n) noexcept {
    if (n < 0) n = -n;
    if (n == 0) return 0;

    int64_t x = n >> 1;
    if (n & 1) {
        return ((square(x) + x) << 2) + 1;
    } else {
        return square(x) << 2;
    }
}

int main() {
    // Test Case 1: Standard positive numbers
    assert(square(5) == 25);
    assert(square(7) == 49);
    assert(square(12) == 144);
    assert(square(15) == 225);

    // Test Case 2: Zero and 1
    assert(square(0) == 0);
    assert(square(1) == 1);

    // Test Case 3: Negative numbers
    assert(square(-5) == 25);
    assert(square(-12) == 144);

    // Test Case 4: Larger values
    assert(square(1000) == 1000000);

    // Compile-time verification
    static_assert(square(5) == 25);
    static_assert(square(12) == 144);
    static_assert(square(-7) == 49);

    std::cout << "[PASS] 15_bit_manipulation/8_Calculate_square_of_a_number_without_using_*_pow: all tests passed!\n";
    return 0;
}
