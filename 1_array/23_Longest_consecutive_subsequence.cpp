#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int findLongestConseqSubseq(std::span<const int> arr) {
        std::unordered_set<int> S(arr.begin(), arr.end());
        int ans = 0;

        for (int val : arr) {
            if (!S.contains(val - 1)) {
                int j = val;
                while (S.contains(j)) {
                    j++;
                }
                ans = std::max(ans, j - val);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {2, 6, 1, 9, 4, 5, 3};
    // Consecutive elements: 1, 2, 3, 4, 5, 6 (length 6)
    assert(sol.findLongestConseqSubseq(arr1) == 6);

    std::vector<int> arr2 = {1, 9, 3, 10, 4, 20, 2};
    // Consecutive elements: 1, 2, 3, 4 (length 4)
    assert(sol.findLongestConseqSubseq(arr2) == 4);

    std::vector<int> empty;
    assert(sol.findLongestConseqSubseq(empty) == 0);

    std::cout << "1_array 23_Longest_consecutive_subsequence: All tests passed.\n";
    return 0;
}
