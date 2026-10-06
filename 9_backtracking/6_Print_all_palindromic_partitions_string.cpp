#include <iostream>
#include <vector>
#include <string>

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
    std::cout << "Palindromic partitions of '" << s << "':\n";
    for (const auto& part : partitions) {
        std::cout << "[ ";
        for (const auto& w : part) std::cout << w << " ";
        std::cout << "]\n";
    }
    return 0;
}
