#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

/**
 * Problem: Rotate a Matrix by 90 Degrees Anti-Clockwise
 * Module: 2_matrix
 * Time Complexity: O(N^2)
 * Space Complexity: O(1) in-place auxiliary
 *
 * Description:
 * Rotates an N x N 2D square matrix by 90 degrees in the counter-clockwise direction
 * in-place by first transposing the matrix, then reversing each column.
 */

class Solution {
public:
    void rotateBy90AntiClockwise(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) return;
        size_t n = matrix.size();

        // 1. Transpose the matrix
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2. Reverse each column for 90 degree anti-clockwise
        for (size_t j = 0; j < n; ++j) {
            size_t top = 0;
            size_t bottom = n - 1;
            while (top < bottom) {
                std::swap(matrix[top][j], matrix[bottom][j]);
                top++;
                bottom--;
            }
        }
    }
};

int main() {
    Solution sol;

    // Test Case 1: 3x3 matrix
    {
        std::vector<std::vector<int>> mat = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        sol.rotateBy90AntiClockwise(mat);
        std::vector<std::vector<int>> expected = {
            {3, 6, 9},
            {2, 5, 8},
            {1, 4, 7}
        };
        assert(mat == expected);
    }

    // Test Case 2: 1x1 matrix
    {
        std::vector<std::vector<int>> mat = {{42}};
        sol.rotateBy90AntiClockwise(mat);
        assert(mat == (std::vector<std::vector<int>>{{42}}));
    }

    // Test Case 3: 4x4 matrix
    {
        std::vector<std::vector<int>> mat = {
            { 1,  2,  3,  4},
            { 5,  6,  7,  8},
            { 9, 10, 11, 12},
            {13, 14, 15, 16}
        };
        sol.rotateBy90AntiClockwise(mat);
        std::vector<std::vector<int>> expected = {
            { 4,  8, 12, 16},
            { 3,  7, 11, 15},
            { 2,  6, 10, 14},
            { 1,  5,  9, 13}
        };
        assert(mat == expected);
    }

    std::cout << "[PASS] 2_matrix/7_Rotate_by_90_degree_anti: all tests passed!\n";
    return 0;
}
