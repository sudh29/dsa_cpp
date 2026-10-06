#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <stack>
#include <vector>

/**
 * Problem: Maximum Size Rectangle of All 1s in a Binary Matrix
 * Module: 2_matrix
 * Time Complexity: O(R * C)
 * Space Complexity: O(C) auxiliary
 *
 * Description:
 * Finds the largest rectangular area containing only 1s in a given binary matrix
 * using monotonic stack histogram area optimization.
 */

class Solution {
private:
    [[nodiscard]] int maxHistArea(std::span<const int> hist) const {
        std::stack<int> s;
        int max_area = 0;
        int n = static_cast<int>(hist.size());

        for (int i = 0; i <= n; ++i) {
            int h = (i == n) ? 0 : hist[i];
            while (!s.empty() && hist[s.top()] >= h) {
                int height = hist[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                max_area = std::max(max_area, height * width);
            }
            s.push(i);
        }
        return max_area;
    }

public:
    [[nodiscard]] int maxRectangle(const std::vector<std::vector<int>>& mat) const {
        if (mat.empty() || mat[0].empty()) return 0;
        size_t c = mat[0].size();
        std::vector<int> hist(c, 0);
        int max_area = 0;

        for (const auto& row : mat) {
            for (size_t j = 0; j < c; ++j) {
                hist[j] = (row[j] == 0) ? 0 : hist[j] + 1;
            }
            max_area = std::max(max_area, maxHistArea(hist));
        }
        return max_area;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard 4x4 matrix
    {
        std::vector<std::vector<int>> mat = {
            {0, 1, 1, 0},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0}
        };
        // Rows 1 and 2 form a 2x4 rectangle of 1s -> area 8
        assert(sol.maxRectangle(mat) == 8);
    }

    // Test Case 2: All 1s
    {
        std::vector<std::vector<int>> mat = {
            {1, 1, 1},
            {1, 1, 1}
        };
        assert(sol.maxRectangle(mat) == 6);
    }

    // Test Case 3: All 0s
    {
        std::vector<std::vector<int>> mat = {
            {0, 0},
            {0, 0}
        };
        assert(sol.maxRectangle(mat) == 0);
    }

    // Test Case 4: Single 1
    {
        std::vector<std::vector<int>> mat = {{1}};
        assert(sol.maxRectangle(mat) == 1);
    }

    // Test Case 5: Empty matrix
    {
        std::vector<std::vector<int>> mat = {};
        assert(sol.maxRectangle(mat) == 0);
    }

    std::cout << "[PASS] 2_matrix/5_Maximum_size_rectangle: all tests passed!\n";
    return 0;
}
