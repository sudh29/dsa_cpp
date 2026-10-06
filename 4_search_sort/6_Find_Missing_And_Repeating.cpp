#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> findTwoElement(std::vector<int> arr, int n) {
        int repeating = -1, missing = -1;
        for (int i = 0; i < n; i++) {
            int idx = std::abs(arr[i]) - 1;
            if (arr[idx] < 0) {
                repeating = std::abs(arr[i]);
            } else {
                arr[idx] = -arr[idx];
            }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                missing = i + 1;
                break;
            }
        }
        return {repeating, missing};
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {1, 3, 3};
    assert(sol.findTwoElement(arr1, 3) == (std::vector<int>{3, 2}));

    std::vector<int> arr2 = {2, 2};
    assert(sol.findTwoElement(arr2, 2) == (std::vector<int>{2, 1}));

    std::vector<int> arr3 = {1, 2, 3, 4, 4};
    assert(sol.findTwoElement(arr3, 5) == (std::vector<int>{4, 5}));

    std::cout << "6_Find_Missing_And_Repeating tests passed.\n";
    return 0;
}
