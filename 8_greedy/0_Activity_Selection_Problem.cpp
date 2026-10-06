#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <utility>
#include <vector>

class Solution {
public:
    int activitySelection(std::span<const int> start, std::span<const int> end) {
        int n = static_cast<int>(start.size());
        if (n == 0) return 0;
        std::vector<std::pair<int, int>> activities(n);
        for (int i = 0; i < n; i++) activities[i] = {end[i], start[i]};
        std::sort(activities.begin(), activities.end());

        int count = 1;
        int last_end = activities[0].first;

        for (int i = 1; i < n; i++) {
            if (activities[i].second > last_end) {
                count++;
                last_end = activities[i].first;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    std::vector<int> start1 = {1, 3, 2, 5};
    std::vector<int> end1 = {2, 4, 3, 6};
    assert(sol.activitySelection(start1, end1) == 3);

    std::vector<int> start2 = {1};
    std::vector<int> end2 = {2};
    assert(sol.activitySelection(start2, end2) == 1);

    assert(sol.activitySelection({}, {}) == 0);

    std::cout << "0_Activity_Selection_Problem tests passed.\n";
    return 0;
}
