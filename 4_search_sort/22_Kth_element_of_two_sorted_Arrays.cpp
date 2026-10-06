#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    int kthElement(std::span<const int> arr1, std::span<const int> arr2, int k) {
        int n = static_cast<int>(arr1.size());
        int m = static_cast<int>(arr2.size());
        if (n > m) return kthElement(arr2, arr1, k);

        int low = std::max(0, k - m), high = std::min(k, n);
        while (low <= high) {
            int cut1 = (low + high) >> 1;
            int cut2 = k - cut1;

            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                return std::max(l1, l2);
            } else if (l1 > r2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {2, 3, 6, 7, 9};
    std::vector<int> arr2 = {1, 4, 8, 10};
    assert(sol.kthElement(arr1, arr2, 5) == 6);

    std::vector<int> a = {100, 112, 256, 349, 770};
    std::vector<int> b = {72, 86, 113, 119, 265, 445, 892};
    assert(sol.kthElement(a, b, 7) == 256);

    std::vector<int> c = {1}, d = {2};
    assert(sol.kthElement(c, d, 1) == 1);
    assert(sol.kthElement(c, d, 2) == 2);

    std::cout << "22_Kth_element_of_two_sorted_Arrays tests passed.\n";
    return 0;
}
