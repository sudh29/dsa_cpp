#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    std::vector<int> valueEqualToIndex(std::span<const int> arr) {
        std::vector<int> res;
        int n = static_cast<int>(arr.size());
        for (int i = 0; i < n; i++) {
            if (arr[i] == i + 1) { // 1-based indexing
                res.push_back(arr[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {15, 2, 45, 12, 7};
    assert(sol.valueEqualToIndex(arr1) == (std::vector<int>{2}));

    std::vector<int> arr2 = {1};
    assert(sol.valueEqualToIndex(arr2) == (std::vector<int>{1}));

    std::vector<int> arr3 = {2, 3, 4};
    assert(sol.valueEqualToIndex(arr3).empty());

    std::cout << "1_Value_equal_to_index_value tests passed.\n";
    return 0;
}
