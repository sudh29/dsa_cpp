#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    void segregateElements(std::span<int> arr) {
        std::vector<int> temp;
        temp.reserve(arr.size());
        for (int val : arr) {
            if (val >= 0) temp.push_back(val);
        }
        for (int val : arr) {
            if (val < 0) temp.push_back(val);
        }
        for (size_t i = 0; i < arr.size(); ++i) {
            arr[i] = temp[i];
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {1, -1, 3, 2, -7, -5, 11, 6};
    sol.segregateElements(arr);
    std::vector<int> expected = {1, 3, 2, 11, 6, -1, -7, -5};
    assert(arr == expected);

    std::vector<int> allPositive = {1, 2, 3};
    sol.segregateElements(allPositive);
    assert(allPositive == (std::vector<int>{1, 2, 3}));

    std::vector<int> allNegative = {-1, -2, -3};
    sol.segregateElements(allNegative);
    assert(allNegative == (std::vector<int>{-1, -2, -3}));

    std::cout << "1_array 4_Move_all_negative_elements_to_end: All tests passed.\n";
    return 0;
}
