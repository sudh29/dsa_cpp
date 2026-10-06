#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int wordBreak(string A, vector<string> &B) {
        unordered_set<string> dict(B.begin(), B.end());
        int n = A.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.find(A.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n] ? 1 : 0;
    }
};

int main() {
    Solution sol;
    string s = "ilike";
    vector<string> dict = {"i", "like", "sam", "sung"};
    cout << "Can break '" << s << "': " << sol.wordBreak(s, dict) << endl;
    return 0;
}
