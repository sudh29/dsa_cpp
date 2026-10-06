#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minChar(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string combined = s + "$" + rev;

        int n = combined.length();
        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }
            if (combined[i] == combined[len]) len++;
            lps[i] = len;
        }
        return s.length() - lps.back();
    }
};

int main() {
    Solution sol;
    string s = "AACECAAAA";
    cout << "Min chars added to front to make palindrome: " << sol.minChar(s) << endl;
    return 0;
}
