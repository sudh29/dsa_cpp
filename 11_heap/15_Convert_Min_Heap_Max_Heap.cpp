#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

void maxHeapify(std::vector<int> &arr, size_t n, size_t i) {
    size_t largest = i;
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void convertMinToMaxHeap(std::vector<int> &arr) {
    if (arr.empty()) return;
    for (size_t i = arr.size() / 2; i > 0; --i) {
        maxHeapify(arr, arr.size(), i - 1);
    }
}

int main() {
    std::vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    convertMinToMaxHeap(arr);

    // Verify max-heap property
    for (size_t i = 0; i < arr.size(); ++i) {
        size_t l = 2 * i + 1;
        size_t r = 2 * i + 2;
        if (l < arr.size()) assert(arr[i] >= arr[l]);
        if (r < arr.size()) assert(arr[i] >= arr[r]);
    }

    std::cout << "11_heap 15_Convert_Min_Heap_Max_Heap: All tests passed.\n";
    return 0;
}
