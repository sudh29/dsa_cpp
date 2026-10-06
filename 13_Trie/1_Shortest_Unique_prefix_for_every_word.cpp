#include <array>
#include <cassert>
#include <iostream>
#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <vector>

/**
 * Problem: Find Shortest Unique Prefix for Every Word
 * Module: 13_Trie
 * Time Complexity: O(N * L) where N is word count, L is maximum word length
 * Space Complexity: O(ALPHABET_SIZE * N * L)
 *
 * Description:
 * Given an array of unique words, finds the shortest unique prefix for each word
 * using a prefix tree (Trie) tracking branch frequencies.
 */

class Solution {
private:
    struct TrieNode {
        std::array<std::unique_ptr<TrieNode>, 26> children{};
        int freq{0};
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
            cur->freq++;
        }
    }

    std::string findPrefix(std::string_view word) const {
        const TrieNode* cur = root.get();
        std::string prefix;
        for (char c : word) {
            prefix += c;
            size_t idx = static_cast<size_t>(c - 'a');
            cur = cur->children[idx].get();
            if (cur && cur->freq == 1) {
                break;
            }
        }
        return prefix;
    }

public:
    std::vector<std::string> findPrefixes(std::span<const std::string> words) {
        root = std::make_unique<TrieNode>();
        for (const auto& w : words) {
            insert(w);
        }

        std::vector<std::string> res;
        res.reserve(words.size());
        for (const auto& w : words) {
            res.push_back(findPrefix(w));
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard dictionary
    {
        std::vector<std::string> words = {"zebra", "dog", "duck", "dove"};
        auto prefixes = sol.findPrefixes(words);
        std::vector<std::string> expected = {"z", "dog", "du", "dov"};
        assert(prefixes == expected);
    }

    // Test Case 2: Single word
    {
        std::vector<std::string> words = {"single"};
        auto prefixes = sol.findPrefixes(words);
        std::vector<std::string> expected = {"s"};
        assert(prefixes == expected);
    }

    // Test Case 3: Completely distinct prefixes
    {
        std::vector<std::string> words = {"apple", "banana", "cherry"};
        auto prefixes = sol.findPrefixes(words);
        std::vector<std::string> expected = {"a", "b", "c"};
        assert(prefixes == expected);
    }

    // Test Case 4: Long shared prefix
    {
        std::vector<std::string> words = {"geeks", "geeky"};
        auto prefixes = sol.findPrefixes(words);
        std::vector<std::string> expected = {"geeks", "geeky"};
        assert(prefixes == expected);
    }

    std::cout << "[PASS] 13_Trie/1_Shortest_Unique_prefix_for_every_word: all tests passed!\n";
    return 0;
}
