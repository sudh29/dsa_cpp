#include <cassert>
#include <compare>
#include <iostream>

/**
 * Topic: C++20 Three-Way Comparison (Spaceship Operator <=>)
 * Module: 0_basics
 */

struct Point {
    int x;
    int y;
    auto operator<=>(const Point&) const = default;
};

int main() {
    // Primitive types
    int a = 10;
    int b = 20;
    assert((a <=> b) < 0);
    assert((b <=> a) > 0);
    assert((a <=> a) == 0);

    // Custom struct with defaulted spaceship operator
    Point p1{1, 2};
    Point p2{1, 3};
    Point p3{1, 2};

    assert(p1 < p2);
    assert(p1 == p3);
    assert(p2 > p1);
    assert((p1 <=> p2) < 0);

    // Compile-time verification
    static_assert((Point{2, 3} <=> Point{2, 3}) == 0);
    static_assert((Point{1, 5} <=> Point{2, 0}) < 0);

    std::cout << "[PASS] 0_basics/cpp_spaceship_operator: all tests passed!\n";
    return 0;
}
