#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    bool find3Numbers(std::span<const int> arr, int X) {
        if (arr.size() < 3) return false;
        std::vector<int> A(arr.begin(), arr.end());
        std::sort(A.begin(), A.end());

        int n = static_cast<int>(A.size());
        for (int i = 0; i < n - 2; ++i) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = A[i] + A[l] + A[r];
                if (sum == X) return true;
                if (sum < X) l++;
                else r--;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<int> A1 = {1, 4, 45, 6, 10, 8};
    assert(sol.find3Numbers(A1, 13)); // 1 + 4 + 8 = 13

    std::vector<int> A2 = {1, 2, 4, 3, 6};
    assert(sol.find3Numbers(A2, 10)); // 1 + 3 + 6 = 10
    assert(!sol.find3Numbers(A2, 100));

    std::cout << "1_array 27_Triplet_Sum_in_Array: All tests passed.\n";
    return 0;
}
