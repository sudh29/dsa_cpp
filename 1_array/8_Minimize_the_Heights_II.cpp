#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    int getMinDiff(std::span<const int> inputArr, int k) {
        if (inputArr.size() <= 1) return 0;
        std::vector<int> arr(inputArr.begin(), inputArr.end());
        std::sort(arr.begin(), arr.end());

        size_t n = arr.size();
        int ans = arr[n - 1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        for (size_t i = 0; i < n - 1; ++i) {
            int mi = std::min(smallest, arr[i + 1] - k);
            int ma = std::max(largest, arr[i] + k);
            if (mi < 0) continue;
            ans = std::min(ans, ma - mi);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {1, 5, 8, 10};
    assert(sol.getMinDiff(arr1, 2) == 5);

    std::vector<int> arr2 = {3, 9, 12, 16, 20};
    assert(sol.getMinDiff(arr2, 3) == 11);

    std::cout << "1_array 8_Minimize_the_Heights_II: All tests passed.\n";
    return 0;
}
