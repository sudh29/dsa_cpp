#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Train {
    int arr, dep, plat;
};

class Solution {
public:
    static bool comp(const Train &a, const Train &b) {
        return a.dep < b.dep;
    }

    int maxStop(int n, int m, vector<vector<int>> &trains) {
        vector<Train> t(m);
        for (int i = 0; i < m; i++) t[i] = {trains[i][0], trains[i][1], trains[i][2]};
        sort(t.begin(), t.end(), comp);

        vector<int> platformDeparture(n + 1, -1);
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
    vector<vector<int>> trains = {
        {1000, 1030, 1},
        {1010, 1020, 1},
        {1025, 1040, 1},
        {1130, 1145, 2},
        {1130, 1140, 2}
    };
    cout << "Max stopped trains: " << sol.maxStop(2, 5, trains) << endl;
    return 0;
}
