#include <array>
#include <cassert>
#include <iostream>
#include <string_view>

/**
 * Problem: Anagram Checker in Modern C++20
 * Module: 0_basics
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary (fixed 256 array)
 */

[[nodiscard]] constexpr bool are_anagrams(std::string_view s1, std::string_view s2) noexcept {
    if (s1.length() != s2.length()) return false;
    std::array<int, 256> count{};
    for (char c : s1) {
        count[static_cast<unsigned char>(c)]++;
    }
    for (char c : s2) {
        if (--count[static_cast<unsigned char>(c)] < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    assert(are_anagrams("listen", "silent") == true);
    assert(are_anagrams("hello", "world") == false);
    assert(are_anagrams("", "") == true);
    assert(are_anagrams("triangle", "integral") == true);
    assert(are_anagrams("apple", "aple") == false);

    static_assert(are_anagrams("listen", "silent"));
    static_assert(!are_anagrams("hello", "world"));

    std::cout << "[PASS] 0_basics/cpp_anagrams: all tests passed!\n";
    return 0;
}
