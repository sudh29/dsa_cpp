#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

class Solution {
public:
    bool areRotations(std::string_view s1, std::string_view s2) {
        if (s1.length() != s2.length()) return false;
        std::string temp = std::string(s1) + std::string(s1);
        return temp.find(s2) != std::string::npos;
    }
};

int main() {
    Solution sol;
    assert(sol.areRotations("ABCD", "CDAB"));
    assert(sol.areRotations("ABCD", "BCDA"));
    assert(sol.areRotations("ABCD", "ABCD"));
    assert(!sol.areRotations("ABCD", "ACBD"));
    assert(!sol.areRotations("ABCD", "ABCDE"));

    std::cout << "3_string 4_Strings_are_rotations_of_other: All tests passed.\n";
    return 0;
}
