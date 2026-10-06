#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string expand(const string &s, int l, int r) {
        while (l >= 0 && r < (int)s.length() && s[l] == s[r]) {
            l--; r++;
        }
        return s.substr(l + 1, r - l - 1);
    }

    string longestPalin(string s) {
        string longest = "";
        for (int i = 0; i < (int)s.length(); i++) {
            string p1 = expand(s, i, i);
            if (p1.length() > longest.length()) longest = p1;
            string p2 = expand(s, i, i + 1);
            if (p2.length() > longest.length()) longest = p2;
        }
        return longest;
    }
};

int main() {
    Solution sol;
    string s = "aaaabbaa";
    cout << "Longest palindrome in " << s << ": " << sol.longestPalin(s) << endl;
    return 0;
}
