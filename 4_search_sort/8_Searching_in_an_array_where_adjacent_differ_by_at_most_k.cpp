#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <span>
#include <vector>

int search(std::span<const int> arr, int x, int k) {
    int n = static_cast<int>(arr.size());
    int i = 0;
    while (i < n) {
        if (arr[i] == x) return i;
        i += std::max(1, std::abs(arr[i] - x) / k);
    }
    return -1;
}

int main() {
    std::vector<int> arr1 = {4, 5, 6, 7, 6};
    assert(search(arr1, 6, 1) == 2);

    std::vector<int> arr2 = {20, 40, 50};
    assert(search(arr2, 50, 20) == 2);

    std::vector<int> arr3 = {1, 2, 3};
    assert(search(arr3, 10, 1) == -1);

    assert(search({}, 5, 1) == -1);

    std::cout << "8_Searching_in_an_array_where_adjacent_differ_by_at_most_k tests passed.\n";
    return 0;
}
