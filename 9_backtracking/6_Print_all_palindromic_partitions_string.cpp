#include <cassert>
#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(const std::string& s, int low, int high) {
    while (low < high) {
        if (s[low++] != s[high--]) return false;
    }
    return true;
}

void backtrack(int start, const std::string& s, std::vector<std::string>& path,
               std::vector<std::vector<std::string>>& result) {
    if (start == static_cast<int>(s.length())) {
        result.push_back(path);
        return;
    }

    for (int end = start; end < static_cast<int>(s.length()); ++end) {
        if (isPalindrome(s, start, end)) {
            path.push_back(s.substr(start, end - start + 1));
            backtrack(end + 1, s, path, result);
            path.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> allPalindromicPerms(const std::string& S) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> path;
    backtrack(0, S, path, result);
    return result;
}

int main() {
    std::string s = "geeks";
    auto partitions = allPalindromicPerms(s);
    assert(!partitions.empty());
    for (const auto& part : partitions) {
        std::string reconstructed;
        for (const auto& w : part) {
            reconstructed += w;
            assert(isPalindrome(w, 0, static_cast<int>(w.length()) - 1));
        }
        assert(reconstructed == s);
    }

    assert(allPalindromicPerms("a").size() == 1);

    std::cout << "6_Print_all_palindromic_partitions_string tests passed.\n";
    return 0;
}
