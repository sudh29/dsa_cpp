#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id, dead, profit;
};

class Solution {
public:
    static bool comparison(Job a, Job b) {
        return (a.profit > b.profit);
    }

    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, comparison);
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) maxDeadline = max(maxDeadline, arr[i].dead);

        vector<int> slot(maxDeadline + 1, -1);
        int countJobs = 0, jobProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = arr[i].id;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {countJobs, jobProfit};
    }
};

int main() {
    Solution sol;
    Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    auto res = sol.JobScheduling(arr, 4);
    cout << "Jobs scheduled: " << res[0] << ", Total Profit: " << res[1] << endl;
    return 0;
}
