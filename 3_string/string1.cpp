#include <cassert>
#include <iostream>
#include <string_view>

int naivePatternSearch(std::string_view text, std::string_view pattern) {
    if (pattern.empty()) return 0;
    int n = static_cast<int>(text.length());
    int m = static_cast<int>(pattern.length());
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) j++;
        if (j == m) return i;
    }
    return -1;
}

int main() {
    std::string_view text = "aaaaaabc";
    assert(naivePatternSearch(text, "abc") == 5);
    assert(naivePatternSearch(text, "xyz") == -1);
    assert(naivePatternSearch(text, "") == 0);
    assert(naivePatternSearch("hello", "ell") == 1);
    assert(naivePatternSearch("a", "a") == 0);

    std::cout << "string1 tests passed.\n";
    return 0;
}
