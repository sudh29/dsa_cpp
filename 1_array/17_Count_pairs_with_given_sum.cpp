#include <cassert>
#include <iostream>
#include <span>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int getPairsCount(std::span<const int> arr, int k) {
        std::unordered_map<int, int> mp;
        int count = 0;
        for (int val : arr) {
            auto it = mp.find(k - val);
            if (it != mp.end()) {
                count += it->second;
            }
            mp[val]++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {1, 5, 7, 1};
    assert(sol.getPairsCount(arr1, 6) == 2);

    std::vector<int> arr2 = {1, 1, 1, 1};
    assert(sol.getPairsCount(arr2, 2) == 6);

    std::vector<int> arr3 = {10, 12, 10, 15, -1};
    assert(sol.getPairsCount(arr3, 125) == 0);

    std::cout << "1_array 17_Count_pairs_with_given_sum: All tests passed.\n";
    return 0;
}
