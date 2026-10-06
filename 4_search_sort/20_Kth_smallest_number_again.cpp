#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

// Merge overlapping intervals and find the k-th smallest element
long long findKth(std::vector<std::pair<long long, long long>> intervals, long long k) {
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::pair<long long, long long>> merged;
    for (const auto& cur : intervals) {
        if (merged.empty() || merged.back().second < cur.first) {
            merged.push_back(cur);
        } else {
            merged.back().second = std::max(merged.back().second, cur.second);
        }
    }

    for (const auto& p : merged) {
        long long count = p.second - p.first + 1;
        if (k <= count) {
            return p.first + k - 1;
        }
        k -= count;
    }
    return -1;
}

int main() {
    std::vector<std::pair<long long, long long>> intervals = {{1, 5}, {10, 15}};
    assert(findKth(intervals, 6) == 10);
    assert(findKth(intervals, 1) == 1);
    assert(findKth(intervals, 5) == 5);
    assert(findKth(intervals, 11) == 15);
    assert(findKth(intervals, 12) == -1);

    std::vector<std::pair<long long, long long>> overlapping = {{1, 3}, {2, 5}};
    assert(findKth(overlapping, 4) == 4);

    std::cout << "20_Kth_smallest_number_again tests passed.\n";
    return 0;
}
