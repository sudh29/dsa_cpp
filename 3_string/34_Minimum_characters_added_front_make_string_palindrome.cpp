#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Solution {
public:
    int minChar(std::string_view s) {
        if (s.empty()) return 0;
        std::string rev(s.rbegin(), s.rend());
        std::string combined = std::string(s) + "$" + rev;

        int n = static_cast<int>(combined.length());
        std::vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }
            if (combined[i] == combined[len]) len++;
            lps[i] = len;
        }
        return static_cast<int>(s.length()) - lps.back();
    }
};

int main() {
    Solution sol;
    assert(sol.minChar("AACECAAAA") == 2);
    assert(sol.minChar("ABCD") == 3);
    assert(sol.minChar("ABA") == 0);
    assert(sol.minChar("A") == 0);
    assert(sol.minChar("") == 0);

    std::cout << "34_Minimum_characters_added_front_make_string_palindrome tests passed.\n";
    return 0;
}
