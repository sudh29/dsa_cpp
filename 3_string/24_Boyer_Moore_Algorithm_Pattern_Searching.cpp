#include <algorithm>
#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

std::vector<int> boyerMooreSearch(std::string_view txt, std::string_view pat) {
    int m = static_cast<int>(pat.length());
    int n = static_cast<int>(txt.length());
    if (m == 0 || n < m) return {};

    std::vector<int> badchar(256, -1);
    for (int i = 0; i < m; i++) {
        badchar[static_cast<unsigned char>(pat[i])] = i;
    }

    std::vector<int> res;
    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j]) {
            j--;
        }
        if (j < 0) {
            res.push_back(s);
            s += (s + m < n) ? m - badchar[static_cast<unsigned char>(txt[s + m])] : 1;
        } else {
            s += std::max(1, j - badchar[static_cast<unsigned char>(txt[s + j])]);
        }
    }
    return res;
}

int main() {
    std::string_view txt = "ABAAABCD", pat = "ABC";
    auto matches = boyerMooreSearch(txt, pat);
    std::vector<int> expected = {4};
    assert(matches == expected);

    std::string_view txt2 = "AABAACAADAABAABA", pat2 = "AABA";
    std::vector<int> expected2 = {0, 9, 12};
    assert(boyerMooreSearch(txt2, pat2) == expected2);

    assert(boyerMooreSearch("ABC", "XYZ").empty());

    std::cout << "24_Boyer_Moore_Algorithm_Pattern_Searching tests passed.\n";
    return 0;
}
