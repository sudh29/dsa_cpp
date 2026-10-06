#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

bool wordBreak(const std::string& s, const std::vector<std::string>& dictionary) {
    std::unordered_set<std::string> dict(dictionary.begin(), dictionary.end());
    int n = s.length();
    std::vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
    std::vector<std::string> dict = {"apple", "pen", "applepen", "pine", "pineapple"};
    std::string s = "pineapplepenapple";
    std::cout << "Can break 'pineapplepenapple': " << (wordBreak(s, dict) ? "YES" : "NO") << "\n";
    return 0;
}
