#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
    struct Node {
        int val;
        size_t row;
        size_t col;

        bool operator>(const Node &other) const {
            return val > other.val;
        }
    };

    std::pair<int, int> findSmallestRange(const std::vector<std::vector<int>> &kSortedArray) {
        if (kSortedArray.empty()) return {-1, -1};
        for (const auto &row : kSortedArray) {
            if (row.empty()) return {-1, -1};
        }

        std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
        int maxVal = INT_MIN;

        for (size_t i = 0; i < kSortedArray.size(); ++i) {
            pq.push({kSortedArray[i][0], i, 0});
            maxVal = std::max(maxVal, kSortedArray[i][0]);
        }

        int start = -1;
        int end = -1;
        int minRange = INT_MAX;

        while (true) {
            auto top = pq.top();
            pq.pop();
            int minVal = top.val;

            if (maxVal - minVal < minRange) {
                minRange = maxVal - minVal;
                start = minVal;
                end = maxVal;
            }

            if (top.col + 1 < kSortedArray[top.row].size()) {
                int nextVal = kSortedArray[top.row][top.col + 1];
                pq.push({nextVal, top.row, top.col + 1});
                maxVal = std::max(maxVal, nextVal);
            } else {
                break;
            }
        }
        return {start, end};
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> arr = {
        {1, 3, 5, 7, 9},
        {0, 2, 4, 6, 8},
        {2, 3, 5, 7, 11}
    };
    auto range = sol.findSmallestRange(arr);
    assert(range.first == 1 && range.second == 2);

    std::cout << "11_heap 10_Smallest_range_in_K_lists: All tests passed.\n";
    return 0;
}
