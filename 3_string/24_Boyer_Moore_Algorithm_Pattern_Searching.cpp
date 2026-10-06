#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> boyerMooreSearch(const string &txt, const string &pat) {
    int m = pat.length(), n = txt.length();
    vector<int> badchar(256, -1);
    for (int i = 0; i < m; i++) badchar[(unsigned char)pat[i]] = i;

    vector<int> res;
    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j]) j--;
        if (j < 0) {
            res.push_back(s);
            s += (s + m < n) ? m - badchar[(unsigned char)txt[s + m]] : 1;
        } else {
            s += max(1, j - badchar[(unsigned char)txt[s + j]]);
        }
    }
    return res;
}

int main() {
    string txt = "ABAAABCD", pat = "ABC";
    auto matches = boyerMooreSearch(txt, pat);
    cout << "Boyer-Moore matches at: ";
    for (int m : matches) cout << m << " ";
    cout << endl;
    return 0;
}
