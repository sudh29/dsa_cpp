#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int findPlatform(std::vector<int> arr, std::vector<int> dep) {
        size_t n = arr.size();
        if (n == 0) return 0;
        std::sort(arr.begin(), arr.end());
        std::sort(dep.begin(), dep.end());

        int plat_needed = 1, result = 1;
        size_t i = 1, j = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                plat_needed++;
                i++;
            } else {
                plat_needed--;
                j++;
            }
            if (plat_needed > result) result = plat_needed;
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {900, 940, 950, 1100, 1500, 1800};
    std::vector<int> dep1 = {910, 1200, 1120, 1130, 1900, 2000};
    assert(sol.findPlatform(arr1, dep1) == 3);

    std::vector<int> arr2 = {900, 1100, 1235};
    std::vector<int> dep2 = {1000, 1200, 1240};
    assert(sol.findPlatform(arr2, dep2) == 1);

    assert(sol.findPlatform({}, {}) == 0);

    std::cout << "7_Minimum_Platforms_Problem tests passed.\n";
    return 0;
}
