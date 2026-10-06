#include <array>
#include <cassert>
#include <iostream>
#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <vector>

/**
 * Problem: Word Break Problem using Trie
 * Module: 13_Trie
 * Time Complexity: O(N * L + S^2) where S is string length, N is dict size, L is word length
 * Space Complexity: O(ALPHABET_SIZE * N * L + S)
 *
 * Description:
 * Determines if a string can be segmented into a space-separated sequence
 * of dictionary words using a Trie and dynamic programming memoization.
 */

class Solution {
private:
    struct TrieNode {
        std::array<std::unique_ptr<TrieNode>, 26> children{};
        bool isLeaf{false};
    };

    std::unique_ptr<TrieNode> root;

    void insert(std::string_view word) {
        TrieNode* cur = root.get();
        for (char c : word) {
            size_t idx = static_cast<size_t>(c - 'a');
            if (!cur->children[idx]) {
                cur->children[idx] = std::make_unique<TrieNode>();
            }
            cur = cur->children[idx].get();
        }
        cur->isLeaf = true;
    }

    [[nodiscard]] bool search(std::string_view word) const {
        const TrieNode* cur = root.get();
        for (char c : word) {
            size_t idx = static_cast<size_t>(c - 'a');
            if (!cur->children[idx]) return false;
            cur = cur->children[idx].get();
        }
        return cur && cur->isLeaf;
    }

    bool wordBreakHelper(std::string_view s, size_t start, std::vector<int>& memo) const {
        if (start == s.length()) return true;
        if (memo[start] != -1) return memo[start] == 1;

        for (size_t end = start + 1; end <= s.length(); ++end) {
            std::string_view prefix = s.substr(start, end - start);
            if (search(prefix) && wordBreakHelper(s, end, memo)) {
                memo[start] = 1;
                return true;
            }
        }
        memo[start] = 0;
        return false;
    }

public:
    bool wordBreak(std::string_view s, std::span<const std::string> dictionary) {
        root = std::make_unique<TrieNode>();
        for (const auto& word : dictionary) {
            insert(word);
        }

        std::vector<int> memo(s.length(), -1);
        return wordBreakHelper(s, 0, memo);
    }
};

int main() {
    Solution sol;
    std::vector<std::string> dict = {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream"};

    // Test Case 1: Standard segmentable string
    assert(sol.wordBreak("ilikesamsung", dict) == true);

    // Test Case 2: Segmentable with multiple combinations
    assert(sol.wordBreak("icecream", dict) == true);

    // Test Case 3: Empty string
    assert(sol.wordBreak("", dict) == true);

    // Test Case 4: Non-segmentable string
    assert(sol.wordBreak("ilikeicecreamandpie", dict) == false);

    // Test Case 5: Single character matches
    assert(sol.wordBreak("i", dict) == true);

    std::cout << "[PASS] 13_Trie/2_Word_Break_Problem_Trie_solution: all tests passed!\n";
    return 0;
}
