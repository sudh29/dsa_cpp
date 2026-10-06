#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Median in a Row-wise Sorted Matrix
 * Module: 2_matrix
 * Time Complexity: O(32 * R * log C)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Given a row-wise sorted matrix of size R x C where R and C are odd,
 * finds the median element across all elements using binary search on answer.
 */

class Solution {
private:
    [[nodiscard]] int countSmallerThanOrEqual(std::span<const int> row, int mid) const {
        auto it = std::upper_bound(row.begin(), row.end(), mid);
        return static_cast<int>(std::distance(row.begin(), it));
    }

public:
    [[nodiscard]] int median(const std::vector<std::vector<int>>& matrix) const {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int r = static_cast<int>(matrix.size());
        int c = static_cast<int>(matrix[0].size());

        int low = INT_MAX;
        int high = INT_MIN;
        for (int i = 0; i < r; ++i) {
            low = std::min(low, matrix[i][0]);
            high = std::max(high, matrix[i][c - 1]);
        }

        int desired = (r * c + 1) / 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 0; i < r; ++i) {
                count += countSmallerThanOrEqual(matrix[i], mid);
            }
            if (count < desired) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;

    // Test Case 1: 3x3 matrix
    {
        std::vector<std::vector<int>> mat = {
            {1, 3, 5},
            {2, 6, 9},
            {3, 6, 9}
        };
        // Elements sorted: 1, 2, 3, 3, 5, 6, 6, 9, 9 -> median at index 4 (5th element) is 5
        assert(sol.median(mat) == 5);
    }

    // Test Case 2: 1x1 matrix
    {
        std::vector<std::vector<int>> mat = {{7}};
        assert(sol.median(mat) == 7);
    }

    // Test Case 3: 3x3 with duplicate values
    {
        std::vector<std::vector<int>> mat = {
            {2, 2, 2},
            {2, 2, 2},
            {2, 2, 2}
        };
        assert(sol.median(mat) == 2);
    }

    std::cout << "[PASS] 2_matrix/2_Median_in_a_row_wise_sorted_Matrix: all tests passed!\n";
    return 0;
}
