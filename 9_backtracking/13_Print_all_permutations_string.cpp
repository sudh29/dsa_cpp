#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

void permute(std::string& s, size_t index, std::vector<std::string>& res) {
    if (index == s.length() - 1) {
        res.push_back(s);
        return;
    }

    std::unordered_set<char> seen;
    for (size_t i = index; i < s.length(); ++i) {
        if (seen.find(s[i]) == seen.end()) {
            seen.insert(s[i]);
            std::swap(s[index], s[i]);
            permute(s, index + 1, res);
            std::swap(s[index], s[i]); // backtrack
        }
    }
}

std::vector<std::string> findPermutation(std::string S) {
    std::sort(S.begin(), S.end());
    std::vector<std::string> res;
    permute(S, 0, res);
    std::sort(res.begin(), res.end());
    return res;
}

int main() {
    auto perms = findPermutation("ABC");
    assert(perms.size() == 6);
    assert(perms.front() == "ABC");
    assert(perms.back() == "CBA");

    assert(findPermutation("A").size() == 1);
    assert(findPermutation("AB").size() == 2);

    std::cout << "13_Print_all_permutations_string tests passed.\n";
    return 0;
}
