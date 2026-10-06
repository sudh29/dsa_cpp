#include <array>
#include <cassert>
#include <iostream>
#include <memory>
#include <span>
#include <vector>

/**
 * Problem: Unique Rows in Boolean Matrix (Binary Trie)
 * Module: 13_Trie
 * Time Complexity: O(R * C) where R is row count, C is column count
 * Space Complexity: O(R * C)
 *
 * Description:
 * Given a binary matrix, finds and prints all unique rows in their original
 * order of appearance using a binary prefix tree (Trie).
 */

class Solution {
private:
    struct TrieNode {
        std::array<std::unique_ptr<TrieNode>, 2> children{};
        bool isLeaf{false};
    };

    bool insertRow(TrieNode* root, std::span<const int> row) {
        TrieNode* cur = root;
        for (int bit : row) {
            size_t idx = static_cast<size_t>(bit & 1);
            if (!cur->children[idx]) {
                cur->children[idx] = std::make_unique<TrieNode>();
            }
            cur = cur->children[idx].get();
        }
        if (cur->isLeaf) {
            return false;
        }
        cur->isLeaf = true;
        return true;
    }

public:
    std::vector<std::vector<int>> uniqueRow(const std::vector<std::vector<int>>& matrix) {
        auto root = std::make_unique<TrieNode>();
        std::vector<std::vector<int>> res;

        for (const auto& row : matrix) {
            if (insertRow(root.get(), row)) {
                res.push_back(row);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard matrix with duplicate rows
    {
        std::vector<std::vector<int>> mat = {
            {1, 1, 0, 1},
            {1, 0, 0, 1},
            {1, 1, 0, 1}
        };
        auto uniq = sol.uniqueRow(mat);
        assert(uniq.size() == 2);
        assert(uniq[0] == (std::vector<int>{1, 1, 0, 1}));
        assert(uniq[1] == (std::vector<int>{1, 0, 0, 1}));
    }

    // Test Case 2: All identical rows
    {
        std::vector<std::vector<int>> mat = {
            {0, 1},
            {0, 1},
            {0, 1}
        };
        auto uniq = sol.uniqueRow(mat);
        assert(uniq.size() == 1);
        assert(uniq[0] == (std::vector<int>{0, 1}));
    }

    // Test Case 3: All distinct rows
    {
        std::vector<std::vector<int>> mat = {
            {0, 0},
            {0, 1},
            {1, 0},
            {1, 1}
        };
        auto uniq = sol.uniqueRow(mat);
        assert(uniq.size() == 4);
    }

    // Test Case 4: Empty matrix
    {
        std::vector<std::vector<int>> empty_mat;
        auto uniq = sol.uniqueRow(empty_mat);
        assert(uniq.empty());
    }

    std::cout << "[PASS] 13_Trie/5_Unique_rows_boolean_matrix: all tests passed!\n";
    return 0;
}
