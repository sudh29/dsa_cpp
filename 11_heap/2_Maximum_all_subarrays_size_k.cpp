#include <cassert>
#include <deque>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Maximum of All Subarrays of Size K (Sliding Window Maximum)
 * Module: 11_heap
 * Time Complexity: O(n)
 * Space Complexity: O(k) deque
 *
 * Description:
 * Computes the maximum value in every contiguous sliding window of size k
 * using a monotonic deque.
 */

class Solution {
public:
    [[nodiscard]] std::vector<int> maxOfSubarrays(std::span<const int> arr, size_t k) const {
        std::vector<int> res;
        if (arr.empty() || k == 0 || k > arr.size()) return res;

        std::deque<size_t> dq;
        res.reserve(arr.size() - k + 1);

        for (size_t i = 0; i < arr.size(); ++i) {
            if (!dq.empty() && dq.front() + k == i) {
                dq.pop_front();
            }
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if (i >= k - 1) {
                res.push_back(arr[dq.front()]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [1, 3, -1, -3, 5, 3, 6, 7] with k = 3
    {
        std::vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
        auto res = sol.maxOfSubarrays(arr, 3);
        std::vector<int> expected = {3, 3, 5, 5, 6, 7};
        assert(res == expected);
    }

    // Test Case 2: k = 1 (each element is its own max)
    {
        std::vector<int> arr = {4, 2, 7};
        auto res = sol.maxOfSubarrays(arr, 1);
        std::vector<int> expected = {4, 2, 7};
        assert(res == expected);
    }

    // Test Case 3: k = arr.size() (single window)
    {
        std::vector<int> arr = {1, 2, 9, 4};
        auto res = sol.maxOfSubarrays(arr, 4);
        assert(res == (std::vector<int>{9}));
    }

    // Test Case 4: Invalid k (k > size)
    {
        std::vector<int> arr = {1, 2};
        assert(sol.maxOfSubarrays(arr, 5).empty());
    }

    std::cout << "[PASS] 11_heap/2_Maximum_all_subarrays_size_k: all tests passed!\n";
    return 0;
}
