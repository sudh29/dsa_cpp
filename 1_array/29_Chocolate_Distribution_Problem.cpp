#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdint>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    int64_t findMinDiff(std::span<const int64_t> inputArr, size_t m) {
        size_t n = inputArr.size();
        if (m == 0 || n == 0 || m > n) return 0;
        std::vector<int64_t> a(inputArr.begin(), inputArr.end());
        std::sort(a.begin(), a.end());
        int64_t minDiff = LLONG_MAX;

        for (size_t i = 0; i + m - 1 < n; ++i) {
            int64_t diff = a[i + m - 1] - a[i];
            minDiff = std::min(minDiff, diff);
        }
        return minDiff;
    }
};

int main() {
    Solution sol;
    std::vector<int64_t> a = {3, 4, 1, 9, 56, 7, 9, 12};
    assert(sol.findMinDiff(a, 5) == 6);

    std::vector<int64_t> b = {7, 3, 2, 4, 9, 12, 56};
    assert(sol.findMinDiff(b, 3) == 2);

    std::cout << "1_array 29_Chocolate_Distribution_Problem: All tests passed.\n";
    return 0;
}
