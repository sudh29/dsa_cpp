#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void selection_sort(std::vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

int main() {
    std::vector<int> arr = {5, 2, 6, 7, 2, 1, 0, 3};
    selection_sort(arr);

    std::cout << "Sorted array (Selection Sort): ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    assert(std::is_sorted(arr.begin(), arr.end()));
    assert(arr.front() == 0 && arr.back() == 7);
    return 0;
}
