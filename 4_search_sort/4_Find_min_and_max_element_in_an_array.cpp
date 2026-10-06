#include <cassert>
#include <climits>
#include <iostream>
#include <span>
#include <utility>
#include <vector>

std::pair<long long, long long> getMinMax(std::span<const long long> a) {
    long long min_val = LLONG_MAX;
    long long max_val = LLONG_MIN;
    for (long long v : a) {
        if (v < min_val) min_val = v;
        if (v > max_val) max_val = v;
    }
    return {min_val, max_val};
}

int main() {
    std::vector<long long> arr1 = {3, 2, 1, 56, 10000, 167};
    auto res1 = getMinMax(arr1);
    assert(res1.first == 1 && res1.second == 10000);

    std::vector<long long> arr2 = {42};
    auto res2 = getMinMax(arr2);
    assert(res2.first == 42 && res2.second == 42);

    std::vector<long long> arr3 = {-10, -50, 0, 20};
    auto res3 = getMinMax(arr3);
    assert(res3.first == -50 && res3.second == 20);

    std::cout << "4_Find_min_and_max_element_in_an_array tests passed.\n";
    return 0;
}
