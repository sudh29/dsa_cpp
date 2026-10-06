#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

constexpr bool is_prime(int n) noexcept {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; static_cast<long long>(i) * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "=== Prime Number Check in C++20 ===\n";

    // Compile-time assertions
    static_assert(!is_prime(0));
    static_assert(!is_prime(1));
    static_assert(is_prime(2));
    static_assert(is_prime(3));
    static_assert(!is_prime(4));
    static_assert(is_prime(17));
    static_assert(is_prime(97));
    static_assert(!is_prime(100));

    const std::vector<std::pair<int, bool>> test_cases = {
        {1, false}, {2, true}, {3, true}, {4, false},
        {17, true}, {19, true}, {20, false}, {29, true},
        {97, true}, {100, false}, {101, true}, {104729, true}
    };

    for (const auto& [num, expected] : test_cases) {
        bool result = is_prime(num);
        std::cout << num << " is " << (result ? "PRIME" : "NOT prime") << "\n";
        assert(result == expected);
    }

    std::cout << "All prime check assertions verified!\n";
    return 0;
}
