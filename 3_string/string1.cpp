#include <iostream>
#include <string>

using namespace std;

int naivePatternSearch(const string &text, const string &pattern) {
    if (pattern.empty()) return 0;
    int n = text.length(), m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) j++;
        if (j == m) return i;
    }
    return -1;
}

int main() {
    string text = "aaaaaabc";
    string p1 = "abc", p2 = "xyz";
    cout << "Pattern '" << p1 << "' in '" << text << "': index " << naivePatternSearch(text, p1) << endl;
    cout << "Pattern '" << p2 << "' in '" << text << "': index " << naivePatternSearch(text, p2) << endl;
    return 0;
}
