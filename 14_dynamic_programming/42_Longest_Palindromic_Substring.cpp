#include <iostream>
#include <string>
#include <algorithm>

std::string longestPalindrome(const std::string& s) {
    int n = s.length();
    if (n <= 1) return s;

    int start = 0, max_len = 1;

    auto expand = [&](int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            int len = r - l + 1;
            if (len > max_len) {
                max_len = len;
                start = l;
            }
            --l;
            ++r;
        }
    };

    for (int i = 0; i < n; ++i) {
        expand(i, i);     // odd length
        expand(i, i + 1); // even length
    }
    return s.substr(start, max_len);
}

int main() {
    std::string s = "babad";
    std::cout << "Longest palindromic substring of 'babad': " << longestPalindrome(s) << "\n";
    return 0;
}
