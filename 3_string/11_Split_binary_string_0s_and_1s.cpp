#include <cassert>
#include <iostream>
#include <string_view>

class Solution {
public:
    int maxSubStr(std::string_view str) {
        int count0 = 0, count1 = 0, splits = 0;
        for (char c : str) {
            if (c == '0') count0++;
            else count1++;
            if (count0 == count1) splits++;
        }
        if (count0 != count1) return -1;
        return splits;
    }
};

int main() {
    Solution sol;
    assert(sol.maxSubStr("0100110101") == 4);
    assert(sol.maxSubStr("0111100010") == 3);
    assert(sol.maxSubStr("000111") == 1);
    assert(sol.maxSubStr("0001") == -1);

    std::cout << "3_string 11_Split_binary_string_0s_and_1s: All tests passed.\n";
    return 0;
}
