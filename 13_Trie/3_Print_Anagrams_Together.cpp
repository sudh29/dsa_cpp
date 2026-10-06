#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <string>
#include <unordered_map>
#include <vector>

/**
 * Problem: Print / Group Anagrams Together
 * Module: 13_Trie
 * Time Complexity: O(N * K log K) where N is number of words, K is max length
 * Space Complexity: O(N * K)
 *
 * Description:
 * Groups words that are mutual anagrams using sorted canonical keys.
 */

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::span<const std::string> words) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (const auto& word : words) {
            std::string sortedKey = word;
            std::sort(sortedKey.begin(), sortedKey.end());
            groups[sortedKey].push_back(word);
        }

        std::vector<std::vector<std::string>> res;
        res.reserve(groups.size());
        for (auto& [key, group] : groups) {
            res.push_back(std::move(group));
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard anagram group set
    {
        std::vector<std::string> words = {"act", "god", "cat", "dog", "tac"};
        auto res = sol.groupAnagrams(words);
        assert(res.size() == 2);
        size_t total_count = 0;
        for (const auto& group : res) {
            total_count += group.size();
        }
        assert(total_count == 5);
    }

    // Test Case 2: All identical anagrams
    {
        std::vector<std::string> words = {"abc", "bca", "cab"};
        auto res = sol.groupAnagrams(words);
        assert(res.size() == 1);
        assert(res[0].size() == 3);
    }

    // Test Case 3: No anagrams
    {
        std::vector<std::string> words = {"apple", "banana", "orange"};
        auto res = sol.groupAnagrams(words);
        assert(res.size() == 3);
    }

    // Test Case 4: Empty list
    {
        std::vector<std::string> empty_words;
        auto res = sol.groupAnagrams(empty_words);
        assert(res.empty());
    }

    std::cout << "[PASS] 13_Trie/3_Print_Anagrams_Together: all tests passed!\n";
    return 0;
}
