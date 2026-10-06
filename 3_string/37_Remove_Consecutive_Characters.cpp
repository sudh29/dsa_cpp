#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

class Solution {
public:
    std::string removeConsecutiveCharacter(std::string_view S) {
        if (S.empty()) return "";
        std::string res;
        res += S[0];
        for (size_t i = 1; i < S.length(); i++) {
            if (S[i] != S[i - 1]) res += S[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    assert(sol.removeConsecutiveCharacter("aabaa") == "aba");
    assert(sol.removeConsecutiveCharacter("aabb") == "ab");
    assert(sol.removeConsecutiveCharacter("a") == "a");
    assert(sol.removeConsecutiveCharacter("aaaaa") == "a");
    assert(sol.removeConsecutiveCharacter("") == "");

    std::cout << "37_Remove_Consecutive_Characters tests passed.\n";
    return 0;
}
