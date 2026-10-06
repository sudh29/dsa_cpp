#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

class Solution {
public:
    bool areIsomorphic(std::string_view str1, std::string_view str2) {
        if (str1.length() != str2.length()) return false;
        std::vector<int> m1(256, -1), m2(256, -1);

        for (size_t i = 0; i < str1.length(); i++) {
            unsigned char c1 = static_cast<unsigned char>(str1[i]);
            unsigned char c2 = static_cast<unsigned char>(str2[i]);
            if (m1[c1] == -1 && m2[c2] == -1) {
                m1[c1] = c2;
                m2[c2] = c1;
            } else if (m1[c1] != c2 || m2[c2] != c1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    assert(sol.areIsomorphic("aab", "xxy"));
    assert(!sol.areIsomorphic("aab", "xyz"));
    assert(sol.areIsomorphic("paper", "title"));
    assert(!sol.areIsomorphic("ab", "aa"));
    assert(sol.areIsomorphic("", ""));

    std::cout << "41_Isomorphic_Strings tests passed.\n";
    return 0;
}
