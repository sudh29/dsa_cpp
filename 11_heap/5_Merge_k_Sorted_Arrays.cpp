#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    struct Element {
        int val;
        size_t row;
        size_t col;

        bool operator>(const Element &other) const {
            return val > other.val;
        }
    };

    std::vector<int> mergeKArrays(const std::vector<std::vector<int>> &arr, size_t K) {
        std::priority_queue<Element, std::vector<Element>, std::greater<Element>> pq;
        for (size_t i = 0; i < K && i < arr.size(); ++i) {
            if (!arr[i].empty()) {
                pq.push({arr[i][0], i, 0});
            }
        }

        std::vector<int> res;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            res.push_back(top.val);
            if (top.col + 1 < arr[top.row].size()) {
                pq.push({arr[top.row][top.col + 1], top.row, top.col + 1});
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> arr = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    auto merged = sol.mergeKArrays(arr, 3);
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(merged == expected);

    std::vector<std::vector<int>> emptyArrays = {{}, {1}, {}};
    auto mergedEmpty = sol.mergeKArrays(emptyArrays, 3);
    assert(mergedEmpty == (std::vector<int>{1}));

    std::cout << "11_heap 5_Merge_k_Sorted_Arrays: All tests passed.\n";
    return 0;
}
