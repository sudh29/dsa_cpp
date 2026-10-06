#include <cassert>
#include <iostream>
#include <string_view>

class Solution {
public:
    int isPalindrome(std::string_view S) {
        if (S.empty()) return 1;
        size_t l = 0, r = S.length() - 1;
        while (l < r) {
            if (S[l++] != S[r--]) return 0;
        }
        return 1;
    }
};

int main() {
    Solution sol;
    assert(sol.isPalindrome("racecar") == 1);
    assert(sol.isPalindrome("aba") == 1);
    assert(sol.isPalindrome("a") == 1);
    assert(sol.isPalindrome("") == 1);
    assert(sol.isPalindrome("abc") == 0);

    std::cout << "3_string 1_Palindrome_String: All tests passed.\n";
    return 0;
}
