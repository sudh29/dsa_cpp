#include <iostream>
#include <compare>

int main() {
    std::cout << "=== C++20 Three-Way Comparison (Spaceship Operator) ===" << std::endl;
    int a = 10, b = 20;
    auto cmp = (a <=> b);

    if (cmp < 0) {
        std::cout << a << " is less than " << b << std::endl;
    } else if (cmp == 0) {
        std::cout << a << " is equal to " << b << std::endl;
    } else {
        std::cout << a << " is greater than " << b << std::endl;
    }

    bool result = (a <=> b) > 0;
    std::cout << "Result of ((10 <=> 20) > 0): " << std::boolalpha << result << std::endl;
    return 0;
}
