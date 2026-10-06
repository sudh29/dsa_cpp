#include <iostream>
#include <utility>
#include <cassert>

void swap_by_ref(int& a, int& b) noexcept {
    int temp = a;
    a = b;
    b = temp;
}

void swap_xor(int& a, int& b) noexcept {
    if (&a != &b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
}

template <typename T>
void swap_move(T& a, T& b) noexcept {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

int main() {
    std::cout << "=== Swapping Techniques in C++20 ===\n";

    int x = 10, y = 20;

    // 1. Pass-by-reference
    swap_by_ref(x, y);
    assert(x == 20 && y == 10);
    std::cout << "After swap_by_ref:  x=" << x << ", y=" << y << "\n";

    // 2. Bitwise XOR
    swap_xor(x, y);
    assert(x == 10 && y == 20);
    std::cout << "After swap_xor:     x=" << x << ", y=" << y << "\n";

    // 3. Move semantics
    swap_move(x, y);
    assert(x == 20 && y == 10);
    std::cout << "After swap_move:    x=" << x << ", y=" << y << "\n";

    // 4. std::swap
    std::swap(x, y);
    assert(x == 10 && y == 20);
    std::cout << "After std::swap:    x=" << x << ", y=" << y << "\n";

    std::cout << "All swapping assertions verified successfully!\n";
    return 0;
}
