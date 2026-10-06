#include <iostream>
#include <vector>
#include <functional>

void swap_refs(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    std::cout << "=== C++ References and Lambdas ===" << std::endl;
    int x = 50, y = 100;
    std::cout << "Before swap: x=" << x << ", y=" << y << std::endl;
    swap_refs(x, y);
    std::cout << "After swap:  x=" << x << ", y=" << y << std::endl;

    // Lambda expressions
    auto multiply = [](int p, int q) -> int { return p * q; };
    std::cout << "Lambda multiply(6, 7): " << multiply(6, 7) << std::endl;

    return 0;
}
