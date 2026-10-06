#include <cassert>
#include <iostream>
#include <vector>

/**
 * Problem: Spirally Traversing a Matrix
 * Module: 2_matrix
 * Time Complexity: O(R * C)
 * Space Complexity: O(1) auxiliary (excluding output)
 *
 * Description:
 * Traverses a 2D matrix in spiral (clockwise perimeter) order.
 */

class Solution {
public:
    [[nodiscard]] std::vector<int> spirallyTraverse(const std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;

        int top = 0;
        int bottom = static_cast<int>(matrix.size()) - 1;
        int left = 0;
        int right = static_cast<int>(matrix[0].size()) - 1;

        res.reserve(matrix.size() * matrix[0].size());

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1: 4x4 matrix
    {
        std::vector<std::vector<int>> mat = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };
        auto res = sol.spirallyTraverse(mat);
        std::vector<int> expected = {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10};
        assert(res == expected);
    }

    // Test Case 2: 1x1 matrix
    {
        std::vector<std::vector<int>> mat = {{42}};
        assert(sol.spirallyTraverse(mat) == (std::vector<int>{42}));
    }

    // Test Case 3: 3x1 single column
    {
        std::vector<std::vector<int>> mat = {{1}, {2}, {3}};
        assert(sol.spirallyTraverse(mat) == (std::vector<int>{1, 2, 3}));
    }

    // Test Case 4: 1x3 single row
    {
        std::vector<std::vector<int>> mat = {{1, 2, 3}};
        assert(sol.spirallyTraverse(mat) == (std::vector<int>{1, 2, 3}));
    }

    // Test Case 5: Empty matrix
    {
        std::vector<std::vector<int>> mat = {};
        assert(sol.spirallyTraverse(mat).empty());
    }

    std::cout << "[PASS] 2_matrix/0_Spirally_traversing_a_matrix: all tests passed!\n";
    return 0;
}
