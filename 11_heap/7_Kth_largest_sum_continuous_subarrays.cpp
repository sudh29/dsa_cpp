#include <cassert>
#include <iostream>
#include <queue>
#include <span>
#include <vector>

class Solution {
public:
    int kthLargest(std::span<const int> arr, int k) {
        size_t n = arr.size();
        assert(k > 0 && static_cast<size_t>(k) <= (n * (n + 1)) / 2);
        std::priority_queue<int, std::vector<int>, std::greater<int>> minH;

        for (size_t i = 0; i < n; ++i) {
            int sum = 0;
            for (size_t j = i; j < n; ++j) {
                sum += arr[j];
                minH.push(sum);
                if (minH.size() > static_cast<size_t>(k)) {
                    minH.pop();
                }
            }
        }
        return minH.top();
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {2, 6, 4, 1};
    // Subarrays:
    // len 1: 2, 6, 4, 1
    // len 2: 8, 10, 5
    // len 3: 12, 11
    // len 4: 13
    // All sums sorted desc: 13, 12, 11, 10, 8, 6, 5, 4, 2, 1
    // 1st largest: 13
    // 2nd largest: 12
    // 3rd largest: 11
    assert(sol.kthLargest(arr, 1) == 13);
    assert(sol.kthLargest(arr, 2) == 12);
    assert(sol.kthLargest(arr, 3) == 11);

    std::cout << "11_heap 7_Kth_largest_sum_continuous_subarrays: All tests passed.\n";
    return 0;
}
