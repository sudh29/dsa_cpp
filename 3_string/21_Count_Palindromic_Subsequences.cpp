#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    long long int countPS(string str) {
        int n = str.length();
        long long int MOD = 1e9 + 7;
        vector<vector<long long int>> dp(n, vector<long long int>(n, 0));

        for (int i = 0; i < n; i++) dp[i][i] = 1;

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i <= n - L; i++) {
                int j = i + L - 1;
                if (str[i] == str[j]) {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
                } else {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution sol;
    string s = "abcd";
    cout << "Palindromic subsequences in '" << s << "': " << sol.countPS(s) << endl;
    return 0;
}
