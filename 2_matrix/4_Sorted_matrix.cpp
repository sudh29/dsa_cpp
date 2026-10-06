#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

/**
 * Problem: Sorted Matrix
 * Module: 2_matrix
 * Time Complexity: O(N^2 log(N^2)) = O(N^2 log N)
 * Space Complexity: O(N^2)
 *
 * Description:
 * Given an N x N matrix, sorts all elements of the matrix in strictly non-decreasing order.
 */

class Solution {
public:
    [[nodiscard]] std::vector<std::vector<int>> sortedMatrix(std::vector<std::vector<int>> mat) {
        if (mat.empty()) return mat;
        size_t n = mat.size();
        size_t m = mat[0].size();

        std::vector<int> temp;
        temp.reserve(n * m);
        for (const auto& row : mat) {
            for (int val : row) {
                temp.push_back(val);
            }
        }

        std::sort(temp.begin(), temp.end());

        size_t k = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                mat[i][j] = temp[k++];
            }
        }
        return mat;
    }
};

int main() {
    Solution sol;

    // Test Case 1: 4x4 matrix
    {
        std::vector<std::vector<int>> mat = {
            {10, 20, 30, 40},
            {15, 25, 35, 45},
            {27, 29, 37, 48},
            {32, 33, 39, 50}
        };
        auto sorted = sol.sortedMatrix(mat);
        assert(sorted[0][0] == 10);
        assert(sorted[3][3] == 50);

        // Verify total ordering
        int prev = -1;
        for (const auto& row : sorted) {
            for (int val : row) {
                assert(val >= prev);
                prev = val;
            }
        }
    }

    // Test Case 2: 1x1 matrix
    {
        std::vector<std::vector<int>> mat = {{5}};
        assert(sol.sortedMatrix(mat) == (std::vector<std::vector<int>>{{5}}));
    }

    // Test Case 3: Empty matrix
    {
        std::vector<std::vector<int>> mat = {};
        assert(sol.sortedMatrix(mat).empty());
    }

    std::cout << "[PASS] 2_matrix/4_Sorted_matrix: all tests passed!\n";
    return 0;
}
