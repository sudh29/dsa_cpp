#include <cassert>
#include <iostream>
#include <vector>

/**
 * Problem: Row with Maximum 1s in a Boolean Matrix
 * Module: 2_matrix
 * Time Complexity: O(N + M)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Given a binary 2D array of size N x M where each row is sorted, finds the
 * 0-based index of the first row with the maximum number of 1s. Returns -1 if no 1s exist.
 */

class Solution {
public:
    [[nodiscard]] int rowWithMax1s(const std::vector<std::vector<int>>& arr) const {
        if (arr.empty() || arr[0].empty()) return -1;
        int n = static_cast<int>(arr.size());
        int m = static_cast<int>(arr[0].size());

        int max_row_idx = -1;
        int j = m - 1;

        for (int i = 0; i < n; ++i) {
            while (j >= 0 && arr[i][j] == 1) {
                j--;
                max_row_idx = i;
            }
        }
        return max_row_idx;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case - row 2 is all 1s
    {
        std::vector<std::vector<int>> arr = {
            {0, 1, 1, 1},
            {0, 0, 1, 1},
            {1, 1, 1, 1},
            {0, 0, 0, 0}
        };
        assert(sol.rowWithMax1s(arr) == 2);
    }

    // Test Case 2: No 1s anywhere
    {
        std::vector<std::vector<int>> arr = {
            {0, 0, 0},
            {0, 0, 0}
        };
        assert(sol.rowWithMax1s(arr) == -1);
    }

    // Test Case 3: First row has max 1s
    {
        std::vector<std::vector<int>> arr = {
            {1, 1, 1},
            {0, 1, 1},
            {0, 0, 1}
        };
        assert(sol.rowWithMax1s(arr) == 0);
    }

    // Test Case 4: Single cell with 1
    {
        std::vector<std::vector<int>> arr = {{1}};
        assert(sol.rowWithMax1s(arr) == 0);
    }

    // Test Case 5: Single cell with 0
    {
        std::vector<std::vector<int>> arr = {{0}};
        assert(sol.rowWithMax1s(arr) == -1);
    }

    std::cout << "[PASS] 2_matrix/3_Row_with_max_1s: all tests passed!\n";
    return 0;
}
