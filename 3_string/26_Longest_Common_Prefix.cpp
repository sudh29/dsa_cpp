#include <cassert>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        std::string prefix = strs[0];

        for (size_t i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> strs1 = {"flower", "flow", "flight"};
    assert(sol.longestCommonPrefix(strs1) == "fl");

    std::vector<std::string> strs2 = {"dog", "racecar", "car"};
    assert(sol.longestCommonPrefix(strs2) == "");

    std::vector<std::string> strs3 = {"interstellar", "interactive", "internet"};
    assert(sol.longestCommonPrefix(strs3) == "inter");

    std::vector<std::string> strs4 = {"single"};
    assert(sol.longestCommonPrefix(strs4) == "single");

    std::vector<std::string> strs5 = {};
    assert(sol.longestCommonPrefix(strs5) == "");

    std::cout << "26_Longest_Common_Prefix tests passed.\n";
    return 0;
}
