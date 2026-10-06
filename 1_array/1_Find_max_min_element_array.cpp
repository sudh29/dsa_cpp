#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdint>
#include <iostream>
#include <span>
#include <utility>
#include <vector>

std::pair<int64_t, int64_t> getMinMax(std::span<const int64_t> a) {
    if (a.empty()) return {0, 0};
    int64_t mn = LLONG_MAX;
    int64_t mx = LLONG_MIN;
    for (int64_t val : a) {
        if (val < mn) mn = val;
        if (val > mx) mx = val;
    }
    return {mn, mx};
}

int main() {
    std::vector<int64_t> arr = {3, 2, 1, 56, 10000, 167};
    auto res = getMinMax(arr);
    assert(res.first == 1);
    assert(res.second == 10000);

    std::vector<int64_t> single = {42};
    auto resSingle = getMinMax(single);
    assert(resSingle.first == 42 && resSingle.second == 42);

    std::cout << "1_array 1_Find_max_min_element_array: All tests passed.\n";
    return 0;
}
