#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    int minJumps(std::span<const int> arr) {
        size_t n = arr.size();
        if (n <= 1) return 0;
        if (arr[0] == 0) return -1;

        size_t maxReach = arr[0];
        size_t step = arr[0];
        int jump = 1;

        for (size_t i = 1; i < n; ++i) {
            if (i == n - 1) return jump;
            maxReach = std::max(maxReach, i + static_cast<size_t>(arr[i]));
            step--;

            if (step == 0) {
                jump++;
                if (i >= maxReach) return -1;
                step = maxReach - i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    assert(sol.minJumps(arr1) == 3);

    std::vector<int> arr2 = {1, 4, 3, 2, 6, 7};
    assert(sol.minJumps(arr2) == 2);

    std::vector<int> arr3 = {0, 1, 2};
    assert(sol.minJumps(arr3) == -1);

    std::cout << "1_array 9_Minimum_number_of_jumps: All tests passed.\n";
    return 0;
}
