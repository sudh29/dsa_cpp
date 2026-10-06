#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
private:
    void permute(std::string &s, size_t l, size_t r, std::vector<std::string> &res) {
        if (l == r) {
            res.push_back(s);
            return;
        }
        for (size_t i = l; i <= r; ++i) {
            std::swap(s[l], s[i]);
            permute(s, l + 1, r, res);
            std::swap(s[l], s[i]);
        }
    }

public:
    std::vector<std::string> findPermutation(std::string S) {
        if (S.empty()) return {};
        std::vector<std::string> res;
        permute(S, 0, S.length() - 1, res);
        std::sort(res.begin(), res.end());
        res.erase(std::unique(res.begin(), res.end()), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    auto perms = sol.findPermutation("ABC");
    std::vector<std::string> expected = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};
    assert(perms == expected);

    auto permsDup = sol.findPermutation("ABA");
    std::vector<std::string> expDup = {"AAB", "ABA", "BAA"};
    assert(permsDup == expDup);

    std::cout << "3_string 10_All_permutations_string: All tests passed.\n";
    return 0;
}
