#include <algorithm>
#include <cassert>
#include <cmath>
#include <climits>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    double medianOfArrays(std::span<const int> array1, std::span<const int> array2) {
        if (array1.size() > array2.size()) {
            return medianOfArrays(array2, array1);
        }

        int n1 = static_cast<int>(array1.size());
        int n2 = static_cast<int>(array2.size());
        int low = 0;
        int high = n1;

        while (low <= high) {
            int cut1 = (low + high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : array1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : array2[cut2 - 1];

            int right1 = (cut1 == n1) ? INT_MAX : array1[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : array2[cut2];

            if (left1 <= right2 && left2 <= right1) {
                if ((n1 + n2) % 2 == 0) {
                    return (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
                } else {
                    return std::max(left1, left2);
                }
            } else if (left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};

int main() {
    Solution sol;
    std::vector<int> a1 = {1, 5, 9};
    std::vector<int> a2 = {2, 3, 6, 7};
    // Merged: 1, 2, 3, 5, 6, 7, 9 (odd length 7, median is 5)
    assert(std::abs(sol.medianOfArrays(a1, a2) - 5.0) < 1e-6);

    std::vector<int> b1 = {4, 6};
    std::vector<int> b2 = {1, 2, 3, 5};
    // Merged: 1, 2, 3, 4, 5, 6 (even length 6, median is (3 + 4) / 2 = 3.5)
    assert(std::abs(sol.medianOfArrays(b1, b2) - 3.5) < 1e-6);

    std::cout << "1_array 35_Median_of_2_Sorted_Arrays_of_Different_Sizes: All tests passed.\n";
    return 0;
}
