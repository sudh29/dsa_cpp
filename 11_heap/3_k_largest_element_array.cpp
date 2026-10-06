#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <span>
#include <vector>

class Solution {
public:
    std::vector<int> kLargest(std::span<const int> arr, int k) {
        if (k <= 0 || static_cast<size_t>(k) > arr.size()) return {};
        std::priority_queue<int, std::vector<int>, std::greater<int>> minH;
        for (int val : arr) {
            minH.push(val);
            if (minH.size() > static_cast<size_t>(k)) {
                minH.pop();
            }
        }
        std::vector<int> res;
        res.reserve(k);
        while (!minH.empty()) {
            res.push_back(minH.top());
            minH.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {12, 5, 787, 1, 23};
    auto res = sol.kLargest(arr, 2);
    assert(res.size() == 2);
    assert(res[0] == 787 && res[1] == 23);

    auto resAll = sol.kLargest(arr, 5);
    assert(resAll.size() == 5);
    assert(std::is_sorted(resAll.rbegin(), resAll.rend()));

    std::cout << "11_heap 3_k_largest_element_array: All tests passed.\n";
    return 0;
}
