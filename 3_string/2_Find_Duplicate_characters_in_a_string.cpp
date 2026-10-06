#include <cassert>
#include <iostream>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

std::vector<std::pair<char, int>> getDuplicates(std::string_view str) {
    std::unordered_map<char, int> count;
    for (char c : str) count[c]++;

    std::vector<std::pair<char, int>> dups;
    for (const auto &[ch, freq] : count) {
        if (freq > 1) {
            dups.push_back({ch, freq});
        }
    }
    return dups;
}

int main() {
    auto dups = getDuplicates("test string");
    // 't' appears 3 times, 's' appears 2 times
    int tCount = 0, sCount = 0;
    for (const auto &[ch, freq] : dups) {
        if (ch == 't') tCount = freq;
        if (ch == 's') sCount = freq;
    }
    assert(tCount == 3);
    assert(sCount == 2);

    auto noDups = getDuplicates("abcde");
    assert(noDups.empty());

    std::cout << "3_string 2_Find_Duplicate_characters_in_a_string: All tests passed.\n";
    return 0;
}
