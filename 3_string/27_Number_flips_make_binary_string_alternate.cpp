#include <algorithm>
#include <cassert>
#include <iostream>
#include <string_view>

class Solution {
public:
    int minFlips(std::string_view S) {
        int flips0 = 0, flips1 = 0;
        for (size_t i = 0; i < S.length(); i++) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';
            if (S[i] != expected0) flips0++;
            if (S[i] != expected1) flips1++;
        }
        return std::min(flips0, flips1);
    }
};

int main() {
    Solution sol;
    assert(sol.minFlips("0001010111") == 2);
    assert(sol.minFlips("001") == 1);
    assert(sol.minFlips("000") == 1);
    assert(sol.minFlips("010101") == 0);
    assert(sol.minFlips("") == 0);

    std::cout << "27_Number_flips_make_binary_string_alternate tests passed.\n";
    return 0;
}
