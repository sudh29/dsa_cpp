#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    void threeWayPartition(std::span<int> array, int a, int b) {
        int low = 0;
        int mid = 0;
        int high = static_cast<int>(array.size()) - 1;

        while (mid <= high) {
            if (array[mid] < a) {
                std::swap(array[low++], array[mid++]);
            } else if (array[mid] > b) {
                std::swap(array[mid], array[high--]);
            } else {
                mid++;
            }
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int a = 10, b = 20;
    sol.threeWayPartition(arr, a, b);

    // Verify partitioning: elements < a come first, then in [a, b], then > b
    int state = 0; // 0: < a, 1: in [a, b], 2: > b
    for (int v : arr) {
        if (v < a) {
            assert(state == 0);
        } else if (v <= b) {
            if (state == 0) state = 1;
            assert(state <= 1);
        } else {
            state = 2;
        }
    }

    std::cout << "1_array 31_Three_way_partitioning: All tests passed.\n";
    return 0;
}
