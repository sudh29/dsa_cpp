#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    void reverseString(std::span<char> s) {
        if (s.empty()) return;
        size_t l = 0, r = s.size() - 1;
        while (l < r) {
            std::swap(s[l++], s[r--]);
        }
    }
};

int main() {
    Solution sol;
    std::vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(s1);
    std::vector<char> exp1 = {'o', 'l', 'l', 'e', 'h'};
    assert(s1 == exp1);

    std::vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    sol.reverseString(s2);
    std::vector<char> exp2 = {'h', 'a', 'n', 'n', 'a', 'H'};
    assert(s2 == exp2);

    std::cout << "3_string 0_Reverse_String: All tests passed.\n";
    return 0;
}
