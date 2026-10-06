#include <array>
#include <cassert>
#include <iostream>
#include <memory>
#include <set>
#include <span>
#include <string>
#include <string_view>
#include <vector>

/**
 * Problem: Implement a Phone Directory using Trie
 * Module: 13_Trie
 * Time Complexity: O(N * L + |s| * N)
 * Space Complexity: O(ALPHABET_SIZE * N * L)
 *
 * Description:
 * Given a list of contacts and a query string s, displays all contacts
 * matching every prefix of s in lexicographical order.
 */

class Solution {
private:
    struct TrieNode {
        std::array<std::unique_ptr<TrieNode>, 26> children{};
        std::set<std::string> contacts;
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
            cur->contacts.insert(std::string(word));
        }
    }

public:
    std::vector<std::vector<std::string>> displayContacts(
        std::span<const std::string> contacts, std::string_view query) {
        root = std::make_unique<TrieNode>();
        for (const auto& contact : contacts) {
            insert(contact);
        }

        std::vector<std::vector<std::string>> res;
        res.reserve(query.length());
        const TrieNode* cur = root.get();
        bool missing = false;

        for (char c : query) {
            size_t idx = static_cast<size_t>(c - 'a');
            if (!missing && cur && cur->children[idx]) {
                cur = cur->children[idx].get();
                res.emplace_back(cur->contacts.begin(), cur->contacts.end());
            } else {
                missing = true;
                res.push_back({"0"});
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> contacts = {"geeikistest", "geeksforgeeks", "geeksfortest"};

    // Test Case 1: Query 'gee' - matches all 3
    {
        auto res = sol.displayContacts(contacts, "gee");
        assert(res.size() == 3);
        // Prefix 'g', 'ge', 'gee' should each have all 3 contacts
        assert(res[0].size() == 3);
        assert(res[1].size() == 3);
        assert(res[2].size() == 3);
        assert(res[2][0] == "geeikistest");
        assert(res[2][1] == "geeksforgeeks");
        assert(res[2][2] == "geeksfortest");
    }

    // Test Case 2: Query extending past matches
    {
        auto res = sol.displayContacts(contacts, "xyz");
        assert(res.size() == 3);
        assert(res[0] == std::vector<std::string>{"0"});
        assert(res[1] == std::vector<std::string>{"0"});
        assert(res[2] == std::vector<std::string>{"0"});
    }

    // Test Case 3: Single contact
    {
        std::vector<std::string> single = {"alice"};
        auto res = sol.displayContacts(single, "ali");
        assert(res.size() == 3);
        assert(res[2] == std::vector<std::string>{"alice"});
    }

    std::cout << "[PASS] 13_Trie/4_Phone_directory: all tests passed!\n";
    return 0;
}
