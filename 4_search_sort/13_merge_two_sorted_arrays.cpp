#include <cassert>
#include <iostream>
#include <span>
#include <vector>

std::vector<int> mergeArrays(std::span<const int> arr1, std::span<const int> arr2) {
    std::vector<int> res;
    res.reserve(arr1.size() + arr2.size());
    size_t i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            res.push_back(arr1[i++]);
        } else {
            res.push_back(arr2[j++]);
        }
    }
    while (i < arr1.size()) res.push_back(arr1[i++]);
    while (j < arr2.size()) res.push_back(arr2[j++]);
    return res;
}

int main() {
    std::vector<int> arr1 = {1, 3, 5, 7};
    std::vector<int> arr2 = {2, 4, 6, 8};
    auto merged = mergeArrays(arr1, arr2);
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8};
    assert(merged == expected);

    assert(mergeArrays({}, arr2) == arr2);
    assert(mergeArrays(arr1, {}) == arr1);
    assert(mergeArrays({}, {}).empty());

    std::cout << "13_merge_two_sorted_arrays tests passed.\n";
    return 0;
}
