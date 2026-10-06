#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    void rearrange(std::span<int> arr) {
        std::vector<int> pos, neg;
        for (int val : arr) {
            if (val >= 0) pos.push_back(val);
            else neg.push_back(val);
        }

        size_t i = 0;
        size_t p = 0, q = 0;
        while (p < pos.size() && q < neg.size()) {
            arr[i++] = pos[p++];
            arr[i++] = neg[q++];
        }
        while (p < pos.size()) arr[i++] = pos[p++];
        while (q < neg.size()) arr[i++] = neg[q++];
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    sol.rearrange(arr);
    std::vector<int> expected = {9, -2, 4, -1, 5, -5, 0, -3, 2};
    assert(arr == expected);

    std::vector<int> allPos = {1, 2, 3};
    sol.rearrange(allPos);
    assert(allPos == (std::vector<int>{1, 2, 3}));

    std::cout << "1_array 19_Alternate_positive_and_negative_numbers: All tests passed.\n";
    return 0;
}
