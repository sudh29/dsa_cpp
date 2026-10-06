#include <cassert>
#include <cstdint>
#include <iostream>
#include <queue>
#include <span>
#include <vector>

class Solution {
public:
    int64_t minCost(std::span<const int64_t> arr) {
        std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> pq;
        for (int64_t rope : arr) {
            pq.push(rope);
        }

        int64_t totalCost = 0;
        while (pq.size() > 1) {
            int64_t first = pq.top(); pq.pop();
            int64_t second = pq.top(); pq.pop();
            int64_t cost = first + second;
            totalCost += cost;
            pq.push(cost);
        }
        return totalCost;
    }
};

int main() {
    Solution sol;
    std::vector<int64_t> ropes = {4, 3, 2, 6};
    // Steps:
    // (2, 3) -> cost 5, remaining: 4, 5, 6
    // (4, 5) -> cost 9, remaining: 6, 9
    // (6, 9) -> cost 15, remaining: 15
    // Total cost: 5 + 9 + 15 = 29
    assert(sol.minCost(ropes) == 29);

    std::vector<int64_t> singleRope = {42};
    assert(sol.minCost(singleRope) == 0);

    std::cout << "11_heap 13_Minimum_Cost_of_ropes: All tests passed.\n";
    return 0;
}
