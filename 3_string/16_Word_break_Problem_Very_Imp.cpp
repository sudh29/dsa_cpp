#include <cassert>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int wordBreak(std::string_view A, const std::vector<std::string>& B) {
        std::unordered_set<std::string_view> dict(B.begin(), B.end());
        size_t n = A.length();
        std::vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (size_t i = 1; i <= n; i++) {
            for (size_t j = 0; j < i; j++) {
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
    std::vector<std::string> dict1 = {"i", "like", "sam", "sung"};
    assert(sol.wordBreak("ilike", dict1) == 1);
    assert(sol.wordBreak("ilikesamsung", dict1) == 1);
    assert(sol.wordBreak("samsungandmango", dict1) == 0);

    std::vector<std::string> dict2 = {"sam", "sung", "and", "mango"};
    assert(sol.wordBreak("samsungandmango", dict2) == 1);

    std::vector<std::string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    assert(sol.wordBreak("catsandog", dict3) == 0);

    std::cout << "16_Word_break_Problem_Very_Imp tests passed.\n";
    return 0;
}
