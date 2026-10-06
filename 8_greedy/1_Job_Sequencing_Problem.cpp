#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

struct Job {
    int id, dead, profit;
};

class Solution {
public:
    static bool comparison(const Job& a, const Job& b) {
        return (a.profit > b.profit);
    }

    std::vector<int> JobScheduling(std::vector<Job> arr) {
        std::sort(arr.begin(), arr.end(), comparison);
        int maxDeadline = 0;
        for (const auto& job : arr) {
            maxDeadline = std::max(maxDeadline, job.dead);
        }

        std::vector<int> slot(maxDeadline + 1, -1);
        int countJobs = 0, jobProfit = 0;

        for (const auto& job : arr) {
            for (int j = job.dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = job.id;
                    countJobs++;
                    jobProfit += job.profit;
                    break;
                }
            }
        }
        return {countJobs, jobProfit};
    }
};

int main() {
    Solution sol;
    std::vector<Job> arr1 = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    auto res1 = sol.JobScheduling(arr1);
    assert(res1[0] == 2 && res1[1] == 60);

    std::vector<Job> arr2 = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}};
    auto res2 = sol.JobScheduling(arr2);
    assert(res2[0] == 2 && res2[1] == 127);

    assert((sol.JobScheduling({}) == std::vector<int>{0, 0}));

    std::cout << "1_Job_Sequencing_Problem tests passed.\n";
    return 0;
}
