#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

struct Job {
    int id;
    int dead;
    int profit;
};

class Solution {
public:
    static bool cmp(const Job& a, const Job& b) {
        return a.profit > b.profit;
    }

    std::vector<int> JobScheduling(std::vector<Job> arr) {
        std::sort(arr.begin(), arr.end(), cmp);
        int max_dead = 0;
        for (const auto& job : arr) {
            max_dead = std::max(max_dead, job.dead);
        }

        std::vector<int> slot(max_dead + 1, -1);
        int count = 0, total_profit = 0;

        for (const auto& job : arr) {
            for (int j = job.dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = job.id;
                    count++;
                    total_profit += job.profit;
                    break;
                }
            }
        }
        return {count, total_profit};
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

    std::cout << "26_Job_Scheduling_Algo tests passed.\n";
    return 0;
}
