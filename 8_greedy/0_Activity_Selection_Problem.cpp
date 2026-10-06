#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int activitySelection(vector<int> start, vector<int> end, int n) {
        vector<pair<int, int>> activities(n);
        for (int i = 0; i < n; i++) activities[i] = {end[i], start[i]};
        sort(activities.begin(), activities.end());

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
    vector<int> start = {1, 3, 2, 5};
    vector<int> end = {2, 4, 3, 6};
    cout << "Max activities: " << sol.activitySelection(start, end, 4) << endl;
    return 0;
}
