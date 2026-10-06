#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    // Dutch National Flag Algorithm
    void sort012(std::span<int> a) {
        if (a.empty()) return;
        int low = 0, mid = 0, high = static_cast<int>(a.size()) - 1;
        while (mid <= high) {
            if (a[mid] == 0) {
                std::swap(a[low++], a[mid++]);
            } else if (a[mid] == 1) {
                mid++;
            } else {
                std::swap(a[mid], a[high--]);
            }
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {0, 2, 1, 2, 0};
    sol.sort012(arr);
    std::vector<int> expected = {0, 0, 1, 2, 2};
    assert(arr == expected);

    std::vector<int> allTwos = {2, 2, 2};
    sol.sort012(allTwos);
    assert(allTwos == (std::vector<int>{2, 2, 2}));

    std::vector<int> reversed = {2, 1, 0};
    sol.sort012(reversed);
    assert(reversed == (std::vector<int>{0, 1, 2}));

    std::cout << "1_array 3_Sort_an_array_of_0s,_1s_and_2s: All tests passed.\n";
    return 0;
}
