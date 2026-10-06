#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Minimum insertions to form a palindrome = n - LPS(s)
    int countMin(string str) {
        int n = str.length();
        string rev = str;
        reverse(rev.begin(), rev.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (str[i - 1] == rev[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return n - dp[n][n];
    }
};

int main() {
    Solution sol;
    string s = "abcd";
    cout << "Min insertions to form palindrome for '" << s << "': " << sol.countMin(s) << endl;
    return 0;
}
