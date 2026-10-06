#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

/**
 * Problem: Common Elements in All Rows of a Given Matrix
 * Module: 2_matrix
 * Time Complexity: O(R * C)
 * Space Complexity: O(C) auxiliary
 *
 * Description:
 * Finds all elements that are present in every row of a given R x C matrix.
 */

class Solution {
public:
    [[nodiscard]] std::vector<int> distinct(const std::vector<std::vector<int>>& matrix) const {
        std::vector<int> res;
        if (matrix.empty()) return res;
        size_t r = matrix.size();

        std::unordered_map<int, size_t> mp;
        for (int val : matrix[0]) {
            mp[val] = 1;
        }

        for (size_t i = 1; i < r; ++i) {
            for (int val : matrix[i]) {
                if (auto it = mp.find(val); it != mp.end() && it->second == i) {
                    it->second = i + 1;
                }
            }
        }

        for (const auto& [val, count] : mp) {
            if (count == r) {
                res.push_back(val);
            }
        }

        std::sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard 4x4 matrix
    {
        std::vector<std::vector<int>> mat = {
            {2, 1, 4, 3},
            {1, 2, 3, 2},
            {3, 6, 2, 3},
            {5, 2, 5, 3}
        };
        // 2 and 3 appear in every row
        auto common = sol.distinct(mat);
        assert(common == (std::vector<int>{2, 3}));
    }

    // Test Case 2: Single row
    {
        std::vector<std::vector<int>> mat = {{1, 2, 2, 3}};
        auto common = sol.distinct(mat);
        assert(common == (std::vector<int>{1, 2, 3}));
    }

    // Test Case 3: No common elements
    {
        std::vector<std::vector<int>> mat = {
            {1, 2},
            {3, 4}
        };
        auto common = sol.distinct(mat);
        assert(common.empty());
    }

    // Test Case 4: All identical rows
    {
        std::vector<std::vector<int>> mat = {
            {5, 10},
            {5, 10},
            {5, 10}
        };
        auto common = sol.distinct(mat);
        assert(common == (std::vector<int>{5, 10}));
    }

    std::cout << "[PASS] 2_matrix/9_Common_elements_in_all_rows_of_a_given_matrix: all tests passed!\n";
    return 0;
}
