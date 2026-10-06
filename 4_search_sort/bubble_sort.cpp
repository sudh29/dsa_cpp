#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void bubble_sort(std::vector<int>& arr) {
    size_t n = arr.size();
    for (size_t k = 1; k < n; ++k) {
        bool swapped = false;
        for (size_t i = 0; i < n - k; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    std::vector<int> arr = {8, 2, 6, 7, 2, 1, 0, 3};
    bubble_sort(arr);

    std::cout << "Sorted array (Bubble Sort): ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    assert(std::is_sorted(arr.begin(), arr.end()));
    assert(arr.front() == 0 && arr.back() == 8);
    return 0;
}
