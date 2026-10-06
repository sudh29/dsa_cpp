#include <array>
#include <cassert>
#include <iostream>
#include <memory>
#include <string_view>

/**
 * Problem: Construct a Trie from Scratch (Prefix Tree)
 * Module: 13_Trie
 * Time Complexity: O(L) per insert/search where L is string length
 * Space Complexity: O(ALPHABET_SIZE * N * L)
 *
 * Description:
 * Implements an efficient prefix tree (Trie) in modern C++20 with full RAII
 * memory safety using std::unique_ptr, support for insert, search, and startsWith,
 * and zero memory leaks.
 */

class Trie {
private:
    struct TrieNode {
        std::array<std::unique_ptr<TrieNode>, 26> children{};
        bool isEndOfWord{false};
    };

    std::unique_ptr<TrieNode> root;

public:
    Trie() : root(std::make_unique<TrieNode>()) {}

    // Rule of 5: Prevent accidental shallow copy, allow move
    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;
    Trie(Trie&&) noexcept = default;
    Trie& operator=(Trie&&) noexcept = default;
    ~Trie() = default;

    void insert(std::string_view key) {
        TrieNode* cur = root.get();
        for (char c : key) {
            size_t idx = static_cast<size_t>(c - 'a');
            if (!cur->children[idx]) {
                cur->children[idx] = std::make_unique<TrieNode>();
            }
            cur = cur->children[idx].get();
        }
        cur->isEndOfWord = true;
    }

    [[nodiscard]] bool search(std::string_view key) const {
        const TrieNode* cur = root.get();
        for (char c : key) {
            size_t idx = static_cast<size_t>(c - 'a');
            if (!cur->children[idx]) return false;
            cur = cur->children[idx].get();
        }
        return cur != nullptr && cur->isEndOfWord;
    }

    [[nodiscard]] bool startsWith(std::string_view prefix) const {
        const TrieNode* cur = root.get();
        for (char c : prefix) {
            size_t idx = static_cast<size_t>(c - 'a');
            if (!cur->children[idx]) return false;
            cur = cur->children[idx].get();
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("the");
    trie.insert("there");
    trie.insert("any");
    trie.insert("answer");

    // Exact matches
    assert(trie.search("the") == true);
    assert(trie.search("there") == true);
    assert(trie.search("any") == true);
    assert(trie.search("answer") == true);

    // Negative matches
    assert(trie.search("these") == false);
    assert(trie.search("th") == false);
    assert(trie.search("an") == false);
    assert(trie.search("zoo") == false);

    // Prefix matches
    assert(trie.startsWith("the") == true);
    assert(trie.startsWith("th") == true);
    assert(trie.startsWith("ans") == true);
    assert(trie.startsWith("xyz") == false);

    std::cout << "[PASS] 13_Trie/0_Construct_trie_from_scratch: all tests passed!\n";
    return 0;
}
