#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> intervals) {
        if (intervals.empty()) return {};
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> res;
        res.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= res.back()[1]) {
                res.back()[1] = std::max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto merged = sol.merge(intervals);
    std::vector<std::vector<int>> expected = {{1, 6}, {8, 10}, {15, 18}};
    assert(merged == expected);

    std::vector<std::vector<int>> empty;
    assert(sol.merge(empty).empty());

    std::cout << "1_array 13_Merge_Intervals: All tests passed.\n";
    return 0;
}
