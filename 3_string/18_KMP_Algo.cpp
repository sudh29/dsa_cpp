#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computeLPS(const string &pat) {
    int m = pat.length();
    vector<int> lps(m, 0);
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

vector<int> KMPSearch(const string &pat, const string &txt) {
    int m = pat.length(), n = txt.length();
    vector<int> lps = computeLPS(pat);
    vector<int> matches;
    int i = 0, j = 0;

    while (i < n) {
        if (pat[j] == txt[i]) {
            i++; j++;
        }
        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return matches;
}

int main() {
    string txt = "ABABDABACDABABCABAB", pat = "ABABCABAB";
    auto res = KMPSearch(pat, txt);
    cout << "KMP pattern found at index: ";
    for (int idx : res) cout << idx << " ";
    cout << endl;
    return 0;
}
