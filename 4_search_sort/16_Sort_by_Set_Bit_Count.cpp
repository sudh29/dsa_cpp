#include <algorithm>
#include <bit>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    static bool comp(int a, int b) {
        return std::popcount(static_cast<unsigned int>(a)) > std::popcount(static_cast<unsigned int>(b));
    }

    void sortBySetBitCount(std::vector<int>& arr) {
        std::stable_sort(arr.begin(), arr.end(), comp);
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    sol.sortBySetBitCount(arr);
    std::vector<int> expected = {15, 7, 5, 3, 9, 6, 2, 4, 32};
    assert(arr == expected);

    std::vector<int> empty;
    sol.sortBySetBitCount(empty);
    assert(empty.empty());

    std::cout << "16_Sort_by_Set_Bit_Count tests passed.\n";
    return 0;
}
