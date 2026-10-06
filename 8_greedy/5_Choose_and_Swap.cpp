#include <cassert>
#include <iostream>
#include <set>
#include <string>

class Solution {
public:
    std::string chooseandswap(std::string a) {
        std::set<char> s(a.begin(), a.end());
        for (size_t i = 0; i < a.length(); i++) {
            s.erase(a[i]);
            if (s.empty()) break;
            char ch = *s.begin();
            if (ch < a[i]) {
                char ch2 = a[i];
                for (size_t j = 0; j < a.length(); j++) {
                    if (a[j] == ch) a[j] = ch2;
                    else if (a[j] == ch2) a[j] = ch;
                }
                break;
            }
        }
        return a;
    }
};

int main() {
    Solution sol;
    assert(sol.chooseandswap("ccad") == "aacd");
    assert(sol.chooseandswap("abba") == "abba");
    assert(sol.chooseandswap("") == "");

    std::cout << "5_Choose_and_Swap tests passed.\n";
    return 0;
}
