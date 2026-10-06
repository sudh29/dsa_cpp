#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

bool wordBreak(const std::string& s, const std::vector<std::string>& dictionary) {
    std::unordered_set<std::string> dict(dictionary.begin(), dictionary.end());
    size_t n = s.length();
    std::vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 0; j < i; ++j) {
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
    assert(wordBreak(s, dict) == true);

    std::vector<std::string> dict2 = {"cats", "dog", "sand", "and", "cat"};
    assert(wordBreak("catsandog", dict2) == false);

    assert(wordBreak("", {}) == true);

    std::cout << "37_Word_Break_Problem tests passed.\n";
    return 0;
}
