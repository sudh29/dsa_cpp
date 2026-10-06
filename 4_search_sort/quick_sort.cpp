#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int partition(std::vector<int>& arr, int start, int end) {
    int pivot = arr[end];
    int pindex = start;

    for (int i = start; i < end; ++i) {
        if (arr[i] <= pivot) {
            std::swap(arr[i], arr[pindex]);
            ++pindex;
        }
    }
    std::swap(arr[pindex], arr[end]);
    return pindex;
}

void quick_sort(std::vector<int>& arr, int start, int end) {
    if (start < end) {
        int pindex = partition(arr, start, end);
        quick_sort(arr, start, pindex - 1);
        quick_sort(arr, pindex + 1, end);
    }
}

int main() {
    std::vector<int> arr = {5, 222, -6, 7, 2, 1, 0, 3};
    if (!arr.empty()) {
        quick_sort(arr, 0, static_cast<int>(arr.size()) - 1);
    }

    std::cout << "Sorted array (Quick Sort): ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    assert(std::is_sorted(arr.begin(), arr.end()));
    assert(arr.front() == -6 && arr.back() == 222);
    return 0;
}
