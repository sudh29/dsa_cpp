#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> overlappedInterval(std::vector<std::vector<int>> intervals) {
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
    auto res = sol.overlappedInterval(intervals);
    std::vector<std::vector<int>> expected = {{1, 6}, {8, 10}, {15, 18}};
    assert(res == expected);

    std::vector<std::vector<int>> empty;
    assert(sol.overlappedInterval(empty).empty());

    std::vector<std::vector<int>> touching = {{1, 4}, {4, 5}};
    std::vector<std::vector<int>> expTouching = {{1, 5}};
    assert(sol.overlappedInterval(touching) == expTouching);

    std::cout << "10_stack_queues 15_Merge_Overlapping_Intervals: All tests passed.\n";
    return 0;
}
