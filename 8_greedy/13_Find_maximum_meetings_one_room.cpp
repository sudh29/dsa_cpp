#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

struct Meeting {
    int start, end, pos;
};

class Solution {
public:
    static bool comp(const Meeting& m1, const Meeting& m2) {
        if (m1.end == m2.end) return m1.pos < m2.pos;
        return m1.end < m2.end;
    }

    std::vector<int> maxMeetings(std::span<const int> start, std::span<const int> end) {
        size_t n = start.size();
        if (n == 0) return {};
        std::vector<Meeting> m(n);
        for (size_t i = 0; i < n; i++) m[i] = {start[i], end[i], static_cast<int>(i + 1)};
        std::sort(m.begin(), m.end(), comp);

        std::vector<int> res;
        res.push_back(m[0].pos);
        int last_end = m[0].end;

        for (size_t i = 1; i < n; i++) {
            if (m[i].start > last_end) {
                res.push_back(m[i].pos);
                last_end = m[i].end;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> s = {1, 3, 0, 5, 8, 5};
    std::vector<int> e = {2, 4, 6, 7, 9, 9};
    auto res = sol.maxMeetings(s, e);
    std::vector<int> expected = {1, 2, 4, 5};
    assert(res == expected);

    assert(sol.maxMeetings({}, {}).empty());

    std::cout << "13_Find_maximum_meetings_one_room tests passed.\n";
    return 0;
}
