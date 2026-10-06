#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> nextPermutation(int N, std::vector<int> arr) {
        int i = N - 2;
        while (i >= 0 && arr[i] >= arr[i + 1]) i--;
        if (i >= 0) {
            int j = N - 1;
            while (arr[j] <= arr[i]) j--;
            std::swap(arr[i], arr[j]);
        }
        std::reverse(arr.begin() + i + 1, arr.end());
        return arr;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {1, 2, 3, 6, 5, 4};
    auto nextp = sol.nextPermutation(static_cast<int>(arr.size()), arr);
    std::vector<int> expected = {1, 2, 4, 3, 5, 6};
    assert(nextp == expected);

    std::vector<int> arr2 = {3, 2, 1};
    assert(sol.nextPermutation(3, arr2) == (std::vector<int>{1, 2, 3}));

    std::vector<int> arr3 = {1, 1, 5};
    assert(sol.nextPermutation(3, arr3) == (std::vector<int>{1, 5, 1}));

    std::cout << "14_Next_Permutation tests passed.\n";
    return 0;
}
