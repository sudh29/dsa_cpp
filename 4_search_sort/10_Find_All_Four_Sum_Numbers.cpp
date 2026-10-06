#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& arr, int k) {
        int n = static_cast<int>(arr.size());
        std::sort(arr.begin(), arr.end());
        std::vector<std::vector<int>> res;

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = static_cast<long long>(arr[i]) + arr[j] + arr[left] + arr[right];
                    if (sum == k) {
                        res.push_back({arr[i], arr[j], arr[left], arr[right]});
                        while (left < right && arr[left] == arr[left + 1]) left++;
                        while (left < right && arr[right] == arr[right - 1]) right--;
                        left++;
                        right--;
                    } else if (sum < k) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {1, 0, -1, 0, -2, 2};
    auto quads1 = sol.fourSum(arr1, 0);
    std::vector<std::vector<int>> expected1 = {
        {-2, -1, 1, 2},
        {-2, 0, 0, 2},
        {-1, 0, 0, 1}
    };
    assert(quads1 == expected1);

    std::vector<int> arr2 = {2, 2, 2, 2, 2};
    auto quads2 = sol.fourSum(arr2, 8);
    std::vector<std::vector<int>> expected2 = {{2, 2, 2, 2}};
    assert(quads2 == expected2);

    std::vector<int> arr3 = {1, 2, 3};
    assert(sol.fourSum(arr3, 10).empty());

    std::cout << "10_Find_All_Four_Sum_Numbers tests passed.\n";
    return 0;
}
