#include <algorithm>
#include <cassert>
#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * Topic: C++ STL Containers & Modern C++20 Ranges
 * Module: 0_basics
 */

int main() {
    // std::vector & std::ranges::sort
    std::vector<int> nums = {5, 2, 9, 1, 5, 6};
    std::ranges::sort(nums);
    assert(std::ranges::is_sorted(nums));
    assert(nums.front() == 1);
    assert(nums.back() == 9);

    // std::unordered_set (Deduplication)
    std::unordered_set<int> unique_vals(nums.begin(), nums.end());
    assert(unique_vals.size() == 5);
    assert(unique_vals.contains(5));
    assert(!unique_vals.contains(42));

    // std::unordered_map & structured bindings
    std::unordered_map<std::string, int> freq;
    freq["apple"] = 3;
    freq["banana"] = 5;

    assert(freq.contains("apple"));
    assert(freq["apple"] == 3);
    assert(freq["banana"] == 5);
    assert(!freq.contains("cherry"));

    std::cout << "[PASS] 0_basics/cpp_stl_containers: all tests passed!\n";
    return 0;
}
