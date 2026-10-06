#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

/**
 * Problem: Find a Specific Pair in Matrix (mat[c][d] - mat[a][b] with c > a and d > b)
 * Module: 2_matrix
 * Time Complexity: O(N^2)
 * Space Complexity: O(N^2)
 *
 * Description:
 * Finds the maximum value of mat[c][d] - mat[a][b] such that c > a and d > b
 * using 2D prefix-suffix dynamic programming.
 */

class Solution {
public:
    [[nodiscard]] int findMaxValue(const std::vector<std::vector<int>>& mat) const {
        if (mat.size() < 2 || mat[0].size() < 2) return 0;
        int n = static_cast<int>(mat.size());
        std::vector<std::vector<int>> maxArr(n, std::vector<int>(n));

        maxArr[n - 1][n - 1] = mat[n - 1][n - 1];
        for (int j = n - 2; j >= 0; --j) {
            maxArr[n - 1][j] = std::max(mat[n - 1][j], maxArr[n - 1][j + 1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            maxArr[i][n - 1] = std::max(mat[i][n - 1], maxArr[i + 1][n - 1]);
        }

        int max_val = INT_MIN;

        for (int i = n - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                max_val = std::max(max_val, maxArr[i + 1][j + 1] - mat[i][j]);
                maxArr[i][j] = std::max(mat[i][j],
                    std::max({maxArr[i + 1][j], maxArr[i][j + 1], maxArr[i + 1][j + 1]}));
            }
        }
        return max_val;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard 4x4 matrix
    {
        std::vector<std::vector<int>> mat = {
            {1, 2, -10, -4},
            {-8, -3, 4, 2},
            {3, 8, 6, 1},
            {-1, -1, 1, 1}
        };
        // Best pair: mat[2][1] - mat[1][0] = 8 - (-8) = 16
        assert(sol.findMaxValue(mat) == 16);
    }

    // Test Case 2: Minimal 2x2 matrix
    {
        std::vector<std::vector<int>> mat = {
            {5, 2},
            {1, 10}
        };
        // Only valid pair is mat[1][1] - mat[0][0] = 10 - 5 = 5
        assert(sol.findMaxValue(mat) == 5);
    }

    // Test Case 3: Negative entries
    {
        std::vector<std::vector<int>> mat = {
            {-1, -2},
            {-3, -4}
        };
        // mat[1][1] - mat[0][0] = -4 - (-1) = -3
        assert(sol.findMaxValue(mat) == -3);
    }

    std::cout << "[PASS] 2_matrix/6_Find_a_specific_pair_in_matrix: all tests passed!\n";
    return 0;
}
