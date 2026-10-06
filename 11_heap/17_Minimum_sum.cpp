#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <string>
#include <vector>

class Solution {
private:
    std::string addStrings(const std::string &num1, const std::string &num2) {
        std::string res;
        int i = static_cast<int>(num1.length()) - 1;
        int j = static_cast<int>(num2.length()) - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            res += static_cast<char>('0' + (sum % 10));
            carry = sum / 10;
        }

        while (res.length() > 1 && res.back() == '0') {
            res.pop_back();
        }
        std::reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }

public:
    std::string solve(std::span<const int> arr) {
        std::vector<int> sortedArr(arr.begin(), arr.end());
        std::sort(sortedArr.begin(), sortedArr.end());

        std::string n1;
        std::string n2;
        for (size_t i = 0; i < sortedArr.size(); ++i) {
            if (sortedArr[i] == 0 && n1.empty() && n2.empty()) continue; // skip leading zeroes
            if (i % 2 == 0) {
                n1 += std::to_string(sortedArr[i]);
            } else {
                n2 += std::to_string(sortedArr[i]);
            }
        }
        if (n1.empty()) n1 = "0";
        if (n2.empty()) n2 = "0";
        return addStrings(n1, n2);
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {6, 8, 4, 5, 2, 3};
    // Sorted: 2, 3, 4, 5, 6, 8
    // n1 = 246, n2 = 358
    // Sum = 604
    assert(sol.solve(arr1) == "604");

    std::vector<int> arr2 = {5, 3, 0, 7, 4};
    // Sorted: 0, 3, 4, 5, 7
    // n1 = 35, n2 = 47 -> 35 + 47 = 82
    assert(sol.solve(arr2) == "82");

    std::cout << "11_heap 17_Minimum_sum: All tests passed.\n";
    return 0;
}
