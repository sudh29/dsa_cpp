#include <cassert>
#include <iostream>
#include <vector>

/**
 * Problem: Search a 2D Matrix (Row-major sorted)
 * Module: 2_matrix
 * Time Complexity: O(log(M * N))
 * Space Complexity: O(1)
 *
 * Description:
 * Searches for a target value in an M x N integer matrix where integers in each
 * row are sorted left to right, and the first integer of each row is greater than
 * the last integer of the previous row.
 */

class Solution {
public:
    [[nodiscard]] bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) const {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        int low = 0;
        int high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int r = mid / n;
            int c = mid % n;
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    // Test Case 1: Present values
    assert(sol.searchMatrix(mat, 3) == true);
    assert(sol.searchMatrix(mat, 1) == true);
    assert(sol.searchMatrix(mat, 60) == true);
    assert(sol.searchMatrix(mat, 16) == true);

    // Test Case 2: Absent values
    assert(sol.searchMatrix(mat, 13) == false);
    assert(sol.searchMatrix(mat, 0) == false);
    assert(sol.searchMatrix(mat, 100) == false);

    // Test Case 3: 1x1 matrix
    assert(sol.searchMatrix({{5}}, 5) == true);
    assert(sol.searchMatrix({{5}}, 2) == false);

    // Test Case 4: Empty matrix
    assert(sol.searchMatrix({}, 1) == false);

    std::cout << "[PASS] 2_matrix/1_Search_a_2D_Matrix: all tests passed!\n";
    return 0;
}
