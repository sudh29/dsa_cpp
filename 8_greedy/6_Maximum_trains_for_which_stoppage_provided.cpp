#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

struct Train {
    int arr, dep, plat;
};

class Solution {
public:
    static bool comp(const Train& a, const Train& b) {
        return a.dep < b.dep;
    }

    int maxStop(int n, int m, const std::vector<std::vector<int>>& trains) {
        if (m == 0 || trains.empty()) return 0;
        std::vector<Train> t(m);
        for (int i = 0; i < m; i++) t[i] = {trains[i][0], trains[i][1], trains[i][2]};
        std::sort(t.begin(), t.end(), comp);

        std::vector<int> platformDeparture(n + 1, -1);
        int count = 0;

        for (int i = 0; i < m; i++) {
            if (platformDeparture[t[i].plat] == -1 || platformDeparture[t[i].plat] <= t[i].arr) {
                platformDeparture[t[i].plat] = t[i].dep;
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> trains = {
        {1000, 1030, 1},
        {1010, 1020, 1},
        {1025, 1040, 1},
        {1130, 1145, 2},
        {1130, 1140, 2}
    };
    assert(sol.maxStop(2, 5, trains) == 3);
    assert(sol.maxStop(2, 0, {}) == 0);

    std::cout << "6_Maximum_trains_for_which_stoppage_provided tests passed.\n";
    return 0;
}
