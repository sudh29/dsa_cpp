#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    int kthSmallest(std::span<const int> arr, size_t k) {
        assert(k > 0 && k <= arr.size());
        std::vector<int> v(arr.begin(), arr.end());
        std::nth_element(v.begin(), v.begin() + k - 1, v.end());
        return v[k - 1];
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {7, 10, 4, 3, 20, 15};
    // Sorted: 3, 4, 7, 10, 15, 20
    assert(sol.kthSmallest(arr, 1) == 3);
    assert(sol.kthSmallest(arr, 3) == 7);
    assert(sol.kthSmallest(arr, 6) == 20);

    std::cout << "1_array 2_Kth_smallest_element: All tests passed.\n";
    return 0;
}
