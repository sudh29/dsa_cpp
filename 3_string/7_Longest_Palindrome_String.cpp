#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

class Solution {
private:
    std::string_view expand(std::string_view s, int l, int r) {
        while (l >= 0 && r < static_cast<int>(s.length()) && s[l] == s[r]) {
            l--; r++;
        }
        return s.substr(l + 1, r - l - 1);
    }

public:
    std::string longestPalin(std::string_view s) {
        std::string_view longest = "";
        for (int i = 0; i < static_cast<int>(s.length()); ++i) {
            auto p1 = expand(s, i, i);
            if (p1.length() > longest.length()) longest = p1;
            auto p2 = expand(s, i, i + 1);
            if (p2.length() > longest.length()) longest = p2;
        }
        return std::string(longest);
    }
};

int main() {
    Solution sol;
    assert(sol.longestPalin("aaaabbaa") == "aabbaa");
    assert(sol.longestPalin("babad") == "bab" || sol.longestPalin("babad") == "aba");
    assert(sol.longestPalin("cbbd") == "bb");
    assert(sol.longestPalin("a") == "a");

    std::cout << "3_string 7_Longest_Palindrome_String: All tests passed.\n";
    return 0;
}
