#include <cassert>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

void generateSubsequences(std::string_view str, size_t idx, std::string current, std::vector<std::string> &res) {
    if (idx == str.length()) {
        if (!current.empty()) res.push_back(current);
        return;
    }
    // Include
    generateSubsequences(str, idx + 1, current + str[idx], res);
    // Exclude
    generateSubsequences(str, idx + 1, current, res);
}

int main() {
    std::string_view s = "abc";
    std::vector<std::string> res;
    generateSubsequences(s, 0, "", res);

    // 2^3 - 1 = 7 non-empty subsequences
    assert(res.size() == 7);

    std::cout << "3_string 9_Print_all_Subsequences_string: All tests passed.\n";
    return 0;
}
