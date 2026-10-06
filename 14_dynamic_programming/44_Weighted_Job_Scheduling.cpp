#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
    int id, deadline, profit;
};

std::pair<int, int> JobScheduling(std::vector<Job>& jobs, int n) {
    std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.profit > b.profit;
    });

    int max_deadline = 0;
    for (const auto& job : jobs) {
        max_deadline = std::max(max_deadline, job.deadline);
    }

    std::vector<int> slot(max_deadline + 1, -1);
    int count = 0, total_profit = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = std::min(max_deadline, jobs[i].deadline); j > 0; --j) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                count++;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }
    return {count, total_profit};
}

int main() {
    std::vector<Job> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    auto [cnt, profit] = JobScheduling(jobs, jobs.size());
    std::cout << "Scheduled jobs: " << cnt << ", Total profit: " << profit << " (expected 2, 60)\n";
    return 0;
}
