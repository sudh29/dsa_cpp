#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Heap Sort
 * Module: 11_heap
 * Time Complexity: O(n log n)
 * Space Complexity: O(1) in-place auxiliary
 *
 * Description:
 * Implements in-place heap sort using max heap construction and root extraction.
 */

class Solution {
public:
    void heapify(std::span<int> arr, size_t n, size_t i) {
        size_t largest = i;
        size_t l = 2 * i + 1;
        size_t r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;

        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void buildHeap(std::span<int> arr) {
        size_t n = arr.size();
        for (size_t i = n / 2; i > 0; --i) {
            heapify(arr, n, i - 1);
        }
    }

    void heapSort(std::span<int> arr) {
        size_t n = arr.size();
        if (n <= 1) return;
        buildHeap(arr);
        for (size_t i = n - 1; i > 0; --i) {
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard array
    {
        std::vector<int> arr = {12, 11, 13, 5, 6, 7};
        sol.heapSort(arr);
        assert(std::is_sorted(arr.begin(), arr.end()));
        assert(arr == (std::vector<int>{5, 6, 7, 11, 12, 13}));
    }

    // Test Case 2: Already sorted
    {
        std::vector<int> arr = {1, 2, 3, 4, 5};
        sol.heapSort(arr);
        assert(std::is_sorted(arr.begin(), arr.end()));
    }

    // Test Case 3: Reverse sorted
    {
        std::vector<int> arr = {5, 4, 3, 2, 1};
        sol.heapSort(arr);
        assert(std::is_sorted(arr.begin(), arr.end()));
    }

    // Test Case 4: Duplicates & negatives
    {
        std::vector<int> arr = {-5, 10, -5, 0, 2};
        sol.heapSort(arr);
        assert(std::is_sorted(arr.begin(), arr.end()));
    }

    std::cout << "[PASS] 11_heap/1_Sort_Array_using_heap_sort: all tests passed!\n";
    return 0;
}
