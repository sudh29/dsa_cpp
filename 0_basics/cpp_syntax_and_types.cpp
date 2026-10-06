#include <iostream>
#include <limits>
#include <cstdint>
#include <cassert>

int main() {
    std::cout << "=== Modern C++ Basic Syntax, Fundamental Types & Limits ===\n";

    auto i = 42;
    auto d = 3.1415926535;
    auto c = 'Z';
    auto b = true;
    int64_t large_val = 9876543210LL;

    std::cout << "int: " << i << " (size: " << sizeof(i) << " bytes)\n";
    std::cout << "double: " << d << " (size: " << sizeof(d) << " bytes)\n";
    std::cout << "char: " << c << " (size: " << sizeof(c) << " bytes)\n";
    std::cout << "bool: " << std::boolalpha << b << " (size: " << sizeof(b) << " bytes)\n";
    std::cout << "int64_t: " << large_val << " (size: " << sizeof(large_val) << " bytes)\n";

    std::cout << "int min: " << std::numeric_limits<int>::min()
              << ", max: " << std::numeric_limits<int>::max() << "\n";
    std::cout << "double min: " << std::numeric_limits<double>::min()
              << ", max: " << std::numeric_limits<double>::max() << "\n";

    // Arithmetic validation
    int a = 20, val = 6;
    assert(a + val == 26);
    assert(a - val == 14);
    assert(a * val == 120);
    assert(a / val == 3);
    assert(a % val == 2);

    constexpr int compile_time_calc = 10 * 5 + 3;
    static_assert(compile_time_calc == 53);

    std::cout << "All syntax and type checks passed!\n";
    return 0;
}
