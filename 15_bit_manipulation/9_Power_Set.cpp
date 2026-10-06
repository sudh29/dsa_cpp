#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

/**
 * Problem: Power Set (All Subsequences of a String)
 * Module: 15_bit_manipulation
 * Time Complexity: O(2^n * n)
 * Space Complexity: O(2^n * n)
 *
 * Description:
 * Generates all non-empty subsequences of a string in lexicographical order
 * using bit manipulation masks.
 */

class Solution {
public:
    [[nodiscard]] std::vector<std::string> allPossibleStrings(std::string_view s) {
        size_t n = s.length();
        size_t total = 1ULL << n;
        std::vector<std::string> res;
        res.reserve(total > 0 ? total - 1 : 0);

        for (size_t i = 1; i < total; ++i) {
            std::string sub;
            for (size_t j = 0; j < n; ++j) {
                if (i & (1ULL << j)) {
                    sub += s[j];
                }
            }
            res.push_back(std::move(sub));
        }

        std::sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard string "abc"
    {
        auto res = sol.allPossibleStrings("abc");
        std::vector<std::string> expected = {"a", "ab", "abc", "ac", "b", "bc", "c"};
        assert(res == expected);
    }

    // Test Case 2: Single character
    {
        auto res = sol.allPossibleStrings("a");
        std::vector<std::string> expected = {"a"};
        assert(res == expected);
    }

    // Test Case 3: Two characters "ab"
    {
        auto res = sol.allPossibleStrings("ab");
        std::vector<std::string> expected = {"a", "ab", "b"};
        assert(res == expected);
    }

    // Test Case 4: Empty string
    {
        auto res = sol.allPossibleStrings("");
        assert(res.empty());
    }

    std::cout << "[PASS] 15_bit_manipulation/9_Power_Set: all tests passed!\n";
    return 0;
}
