#include <cassert>
#include <iostream>
#include <span>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool subArrayExists(std::span<const int> arr) {
        std::unordered_set<int> sumSet;
        int sum = 0;
        for (int val : arr) {
            sum += val;
            if (sum == 0 || sumSet.contains(sum)) {
                return true;
            }
            sumSet.insert(sum);
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {4, 2, -3, 1, 6};
    assert(sol.subArrayExists(arr1));

    std::vector<int> arr2 = {4, 2, 0, 1, 6};
    assert(sol.subArrayExists(arr2));

    std::vector<int> arr3 = {1, 2, 3};
    assert(!sol.subArrayExists(arr3));

    std::cout << "1_array 20_Subarray_with_0_sum: All tests passed.\n";
    return 0;
}
