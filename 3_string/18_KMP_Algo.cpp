#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

std::vector<int> computeLPS(std::string_view pat) {
    int m = static_cast<int>(pat.length());
    std::vector<int> lps(m, 0);
    int len = 0, i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i++] = len;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }
    return lps;
}

std::vector<int> KMPSearch(std::string_view pat, std::string_view txt) {
    int m = static_cast<int>(pat.length());
    int n = static_cast<int>(txt.length());
    if (m == 0 || n < m) return {};

    std::vector<int> lps = computeLPS(pat);
    std::vector<int> matches;
    int i = 0, j = 0;

    while (i < n) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return matches;
}

int main() {
    std::string_view txt = "ABABDABACDABABCABAB", pat = "ABABCABAB";
    auto res = KMPSearch(pat, txt);
    std::vector<int> expected = {10};
    assert(res == expected);

    std::string_view txt2 = "AAAAABAAABA", pat2 = "AAAA";
    std::vector<int> expected2 = {0, 1};
    assert(KMPSearch(pat2, txt2) == expected2);

    assert(KMPSearch("XYZ", "ABC").empty());

    std::cout << "18_KMP_Algo tests passed.\n";
    return 0;
}
