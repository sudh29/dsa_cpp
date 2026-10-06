#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    // Boyer-Moore Voting Algorithm
    int majorityElement(std::span<const int> a) {
        int candidate = -1, count = 0;
        int size = static_cast<int>(a.size());
        for (int i = 0; i < size; i++) {
            if (count == 0) {
                candidate = a[i];
                count = 1;
            } else if (a[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
        // Verification
        int freq = 0;
        for (int i = 0; i < size; i++) {
            if (a[i] == candidate) freq++;
        }
        return (freq > size / 2) ? candidate : -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {3, 1, 3, 3, 2};
    assert(sol.majorityElement(arr1) == 3);

    std::vector<int> arr2 = {1, 2, 3};
    assert(sol.majorityElement(arr2) == -1);

    std::vector<int> arr3 = {2, 2, 2, 2};
    assert(sol.majorityElement(arr3) == 2);

    std::vector<int> arr4 = {1};
    assert(sol.majorityElement(arr4) == 1);

    std::cout << "7_Majority_Element tests passed.\n";
    return 0;
}
