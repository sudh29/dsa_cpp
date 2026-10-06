#include <cassert>
#include <functional>
#include <iostream>
#include <vector>

/**
 * Topic: C++ References, Functions and Lambdas
 * Module: 0_basics
 */

constexpr void swap_refs(int& a, int& b) noexcept {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 50;
    int y = 100;
    swap_refs(x, y);
    assert(x == 100);
    assert(y == 50);

    // Lambda expressions
    auto multiply = [](int p, int q) noexcept -> int { return p * q; };
    assert(multiply(6, 7) == 42);
    assert(multiply(-3, 4) == -12);
    assert(multiply(0, 100) == 0);

    // Generic lambda with auto parameter (C++14/20)
    auto square = [](auto v) noexcept { return v * v; };
    assert(square(5) == 25);
    assert(square(2.5) == 6.25);

    std::cout << "[PASS] 0_basics/cpp_references_and_functions: all tests passed!\n";
    return 0;
}
