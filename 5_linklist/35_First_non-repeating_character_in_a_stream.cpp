#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <string_view>

/**
 * Problem: First Non-Repeating Character in a Stream
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary (queue capped at 26 elements)
 *
 * Description:
 * Given an input stream of characters, finds the first non-repeating character
 * at each step. If none exists, appends '#'.
 */

class Solution {
public:
    [[nodiscard]] std::string firstNonRepeating(std::string_view a) const {
        std::array<int, 26> freq{};
        std::queue<char> q;
        std::string ans;
        ans.reserve(a.length());

        for (char c : a) {
            size_t idx = static_cast<size_t>(c - 'a');
            freq[idx]++;
            q.push(c);

            while (!q.empty() && freq[static_cast<size_t>(q.front() - 'a')] > 1) {
                q.pop();
            }

            if (q.empty()) {
                ans += '#';
            } else {
                ans += q.front();
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: "aabc" -> "a#bb"
    // 'a' -> 'a'
    // 'a' -> '#'
    // 'b' -> 'b'
    // 'c' -> 'b'
    assert(sol.firstNonRepeating("aabc") == "a#bb");

    // Test Case 2: "zz" -> "z#"
    assert(sol.firstNonRepeating("zz") == "z#");

    // Test Case 3: All distinct "abc" -> "aaa"
    assert(sol.firstNonRepeating("abc") == "aaa");

    // Test Case 4: Empty string
    assert(sol.firstNonRepeating("").empty());

    std::cout << "[PASS] 5_linklist/35_First_non-repeating_character_in_a_stream: all tests passed!\n";
    return 0;
}
