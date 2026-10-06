#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int dead;
    int profit;
};

class Solution {
public:
    static bool cmp(const Job &a, const Job &b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, cmp);
        int max_dead = 0;
        for (int i = 0; i < n; i++) max_dead = max(max_dead, arr[i].dead);

        vector<int> slot(max_dead + 1, -1);
        int count = 0, total_profit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = arr[i].id;
                    count++;
                    total_profit += arr[i].profit;
                    break;
                }
            }
        }
        return {count, total_profit};
    }
};

int main() {
    Solution sol;
    Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    auto res = sol.JobScheduling(arr, n);
    cout << "Jobs scheduled: " << res[0] << " | Max Profit: " << res[1] << endl;
    return 0;
}
