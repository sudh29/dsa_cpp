#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    int findMedian(std::span<const int> arr) {
        assert(!arr.empty());
        std::vector<int> v(arr.begin(), arr.end());
        std::sort(v.begin(), v.end());
        size_t n = v.size();
        if (n % 2 != 0) return v[n / 2];
        return (v[n / 2 - 1] + v[n / 2]) / 2;
    }
};

int main() {
    Solution sol;
    std::vector<int> v1 = {90, 100, 78, 89, 67};
    assert(sol.findMedian(v1) == 89);

    std::vector<int> v2 = {56, 67, 30, 79};
    assert(sol.findMedian(v2) == 61);

    std::cout << "1_array 34_Find_the_median: All tests passed.\n";
    return 0;
}
