#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start, end, pos;
};

class Solution {
public:
    static bool comp(Meeting m1, Meeting m2) {
        if (m1.end == m2.end) return m1.pos < m2.pos;
        return m1.end < m2.end;
    }

    vector<int> maxMeetings(int n, int start[], int end[]) {
        vector<Meeting> m(n);
        for (int i = 0; i < n; i++) m[i] = {start[i], end[i], i + 1};
        sort(m.begin(), m.end(), comp);

        vector<int> res;
        res.push_back(m[0].pos);
        int last_end = m[0].end;

        for (int i = 1; i < n; i++) {
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
    int s[] = {1, 3, 0, 5, 8, 5};
    int e[] = {2, 4, 6, 7, 9, 9};
    auto res = sol.maxMeetings(6, s, e);
    cout << "Selected meeting indices: ";
    for (int idx : res) cout << idx << " ";
    cout << endl;
    return 0;
}
