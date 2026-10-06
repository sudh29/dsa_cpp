#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

/**
 * Problem: Kth Smallest Element in a Row-wise and Column-wise Sorted Matrix
 * Module: 2_matrix
 * Time Complexity: O(K log N)
 * Space Complexity: O(N) min-heap size
 *
 * Description:
 * Finds the K-th smallest element in an N x N matrix sorted both row-wise
 * and column-wise using a min-heap priority queue.
 */

class Solution {
private:
    struct Element {
        int val;
        size_t row;
        size_t col;

        bool operator>(const Element& other) const noexcept {
            return val > other.val;
        }
    };

public:
    [[nodiscard]] int kthSmallest(const std::vector<std::vector<int>>& mat, size_t k) const {
        if (mat.empty() || mat[0].empty() || k == 0) return -1;
        size_t n = mat.size();

        std::priority_queue<Element, std::vector<Element>, std::greater<Element>> pq;

        for (size_t i = 0; i < n; ++i) {
            pq.push(Element{mat[i][0], i, 0});
        }

        int res = -1;
        while (k > 0 && !pq.empty()) {
            auto [val, r, c] = pq.top();
            pq.pop();
            res = val;
            --k;

            if (c + 1 < mat[r].size()) {
                pq.push(Element{mat[r][c + 1], r, c + 1});
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> mat = {
        {16, 28, 60, 64},
        {22, 41, 63, 91},
        {27, 50, 87, 93},
        {36, 78, 87, 94}
    };

    // Test Case 1: k = 3 (16, 22, 27 -> 27)
    assert(sol.kthSmallest(mat, 3) == 27);

    // Test Case 2: k = 1 (minimum element)
    assert(sol.kthSmallest(mat, 1) == 16);

    // Test Case 3: k = 16 (maximum element)
    assert(sol.kthSmallest(mat, 16) == 94);

    // Test Case 4: 1x1 matrix
    assert(sol.kthSmallest({{5}}, 1) == 5);

    // Test Case 5: 2x2 matrix
    {
        std::vector<std::vector<int>> small = {
            {1, 2},
            {1, 3}
        };
        assert(sol.kthSmallest(small, 2) == 1);
        assert(sol.kthSmallest(small, 3) == 2);
    }

    std::cout << "[PASS] 2_matrix/8_Kth_element_in_Matrix: all tests passed!\n";
    return 0;
}
