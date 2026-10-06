#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

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
    std::string s = "ABC";
    auto perms = findPermutation(s);
    std::cout << "Permutations of 'ABC': ";
    for (const auto& p : perms) std::cout << p << " ";
    std::cout << "\n";
    return 0;
}
