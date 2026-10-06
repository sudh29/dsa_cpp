#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
private:
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

public:
    std::vector<int> mergeHeaps(std::span<const int> a, std::span<const int> b) {
        std::vector<int> merged;
        merged.reserve(a.size() + b.size());
        merged.insert(merged.end(), a.begin(), a.end());
        merged.insert(merged.end(), b.begin(), b.end());

        if (merged.empty()) return merged;

        size_t total = merged.size();
        for (size_t i = total / 2; i > 0; --i) {
            maxHeapify(merged, total, i - 1);
        }
        return merged;
    }
};

int main() {
    Solution sol;
    std::vector<int> a = {10, 5, 6, 2};
    std::vector<int> b = {12, 7, 9};
    auto merged = sol.mergeHeaps(a, b);

    assert(!merged.empty());
    assert(merged[0] == 12); // Max element at root
    // Verify max-heap property
    for (size_t i = 0; i < merged.size(); ++i) {
        size_t l = 2 * i + 1;
        size_t r = 2 * i + 2;
        if (l < merged.size()) assert(merged[i] >= merged[l]);
        if (r < merged.size()) assert(merged[i] >= merged[r]);
    }

    std::cout << "11_heap 6_Merge_2_Binary_Max_Heaps: All tests passed.\n";
    return 0;
}
