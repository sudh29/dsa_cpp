#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <string>
#include <vector>

class Solution {
public:
    void reverseArray(std::span<int> arr) {
        if (arr.empty()) return;
        size_t left = 0;
        size_t right = arr.size() - 1;
        while (left < right) {
            std::swap(arr[left++], arr[right--]);
        }
    }

    std::string reverseWord(std::string str) {
        std::reverse(str.begin(), str.end());
        return str;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {1, 2, 3, 4, 5};
    sol.reverseArray(arr);
    std::vector<int> expectedArr = {5, 4, 3, 2, 1};
    assert(arr == expectedArr);

    std::vector<int> even = {10, 20, 30, 40};
    sol.reverseArray(even);
    std::vector<int> expectedEven = {40, 30, 20, 10};
    assert(even == expectedEven);

    assert(sol.reverseWord("Geeks") == "skeeG");
    assert(sol.reverseWord("ModernC++") == "++CnredoM");

    std::cout << "1_array 0_Reverse_the_array: All tests passed.\n";
    return 0;
}
