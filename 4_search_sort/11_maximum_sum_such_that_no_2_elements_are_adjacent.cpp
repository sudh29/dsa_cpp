#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    int FindMaxSum(std::span<const int> arr) {
        int n = static_cast<int>(arr.size());
        if (n == 0) return 0;
        int incl = arr[0];
        int excl = 0;
        for (int i = 1; i < n; i++) {
            int new_excl = std::max(incl, excl);
            incl = excl + arr[i];
            excl = new_excl;
        }
        return std::max(incl, excl);
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {5, 5, 10, 100, 10, 5};
    assert(sol.FindMaxSum(arr1) == 110);

    std::vector<int> arr2 = {1, 2, 3};
    assert(sol.FindMaxSum(arr2) == 4);

    std::vector<int> arr3 = {5, 5, 10, 40, 50, 35};
    assert(sol.FindMaxSum(arr3) == 80);

    assert(sol.FindMaxSum({}) == 0);

    std::cout << "11_maximum_sum_such_that_no_2_elements_are_adjacent tests passed.\n";
    return 0;
}
