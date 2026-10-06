#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Implement Max Heap and Min Heap (Array & Recursion)
 * Module: 11_heap
 * Time Complexity: O(n) buildHeap, O(log n) heapify
 * Space Complexity: O(log n) recursion stack
 *
 * Description:
 * Implements standard array-based binary heap operations: maxHeapify, minHeapify,
 * buildMaxHeap, and buildMinHeap.
 */

class Heap {
public:
    static void maxHeapify(std::span<int> arr, size_t i) {
        size_t n = arr.size();
        size_t largest = i;
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;

        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            maxHeapify(arr, largest);
        }
    }

    static void minHeapify(std::span<int> arr, size_t i) {
        size_t n = arr.size();
        size_t smallest = i;
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;

        if (left < n && arr[left] < arr[smallest]) smallest = left;
        if (right < n && arr[right] < arr[smallest]) smallest = right;

        if (smallest != i) {
            std::swap(arr[i], arr[smallest]);
            minHeapify(arr, smallest);
        }
    }

    static void buildMaxHeap(std::span<int> arr) {
        if (arr.empty()) return;
        for (size_t i = arr.size() / 2; i > 0; --i) {
            maxHeapify(arr, i - 1);
        }
    }

    static void buildMinHeap(std::span<int> arr) {
        if (arr.empty()) return;
        for (size_t i = arr.size() / 2; i > 0; --i) {
            minHeapify(arr, i - 1);
        }
    }
};

int main() {
    // Test Case 1: Build max heap
    {
        std::vector<int> arr = {4, 10, 3, 5, 1};
        Heap::buildMaxHeap(arr);
        assert(std::is_heap(arr.begin(), arr.end()));
        assert(arr.front() == 10);
    }

    // Test Case 2: Build min heap
    {
        std::vector<int> arr = {4, 10, 3, 5, 1};
        Heap::buildMinHeap(arr);
        assert(std::is_heap(arr.begin(), arr.end(), std::greater<int>()));
        assert(arr.front() == 1);
    }

    // Test Case 3: Empty and single-element heaps
    {
        std::vector<int> empty;
        Heap::buildMaxHeap(empty);
        assert(empty.empty());

        std::vector<int> single = {42};
        Heap::buildMaxHeap(single);
        assert(single == (std::vector<int>{42}));
    }

    std::cout << "[PASS] 11_heap/0_Implement_Maxheap_MinHeap_arrays_recursion: all tests passed!\n";
    return 0;
}
