#include <cassert>
#include <iostream>
#include <queue>
#include <span>
#include <vector>

class Solution {
public:
    int kthSmallest(std::span<const int> arr, int k) {
        assert(k > 0 && static_cast<size_t>(k) <= arr.size());
        std::priority_queue<int> maxH;
        for (int val : arr) {
            maxH.push(val);
            if (maxH.size() > static_cast<size_t>(k)) {
                maxH.pop();
            }
        }
        return maxH.top();
    }

    int kthLargest(std::span<const int> arr, int k) {
        assert(k > 0 && static_cast<size_t>(k) <= arr.size());
        std::priority_queue<int, std::vector<int>, std::greater<int>> minH;
        for (int val : arr) {
            minH.push(val);
            if (minH.size() > static_cast<size_t>(k)) {
                minH.pop();
            }
        }
        return minH.top();
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {7, 10, 4, 3, 20, 15};
    // Sorted: 3, 4, 7, 10, 15, 20
    assert(sol.kthSmallest(arr, 3) == 7);
    assert(sol.kthSmallest(arr, 1) == 3);
    assert(sol.kthSmallest(arr, 6) == 20);

    assert(sol.kthLargest(arr, 1) == 20);
    assert(sol.kthLargest(arr, 2) == 15);
    assert(sol.kthLargest(arr, 6) == 3);

    std::cout << "11_heap 4_Kth_smallest_largest_element_unsorted_array: All tests passed.\n";
    return 0;
}
