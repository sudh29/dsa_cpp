#include <cassert>
#include <iostream>
#include <string_view>

/**
 * Topic: Pattern Count / Substring Search
 * Module: 0_basics
 * Time Complexity: O(n * m)
 * Space Complexity: O(1)
 */

[[nodiscard]] constexpr int count_pattern_occurrences(
    std::string_view text, std::string_view pattern) noexcept {
    if (pattern.empty() || text.empty()) return 0;
    int count = 0;
    size_t pos = text.find(pattern, 0);
    while (pos != std::string_view::npos) {
        count++;
        pos = text.find(pattern, pos + 1);
    }
    return count;
}

int main() {
    assert(count_pattern_occurrences("abracadabra abracadabra", "abra") == 4);
    assert(count_pattern_occurrences("aaaaa", "aa") == 4);
    assert(count_pattern_occurrences("hello world", "xyz") == 0);
    assert(count_pattern_occurrences("test", "") == 0);
    assert(count_pattern_occurrences("", "test") == 0);
    assert(count_pattern_occurrences("apple", "apple") == 1);

    static_assert(count_pattern_occurrences("abracadabra", "abra") == 2);

    std::cout << "[PASS] 0_basics/cpp_pattern_count: all tests passed!\n";
    return 0;
}
