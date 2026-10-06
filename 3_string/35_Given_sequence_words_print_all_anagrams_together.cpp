#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string>> Anagrams(const std::vector<std::string>& string_list) {
        std::unordered_map<std::string, std::vector<std::string>> mp;
        for (const std::string& s : string_list) {
            std::string key = s;
            std::sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        std::vector<std::vector<std::string>> res;
        for (auto& [key, group] : mp) {
            res.push_back(std::move(group));
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> words = {"act", "god", "cat", "dog", "tac"};
    auto groups = sol.Anagrams(words);
    assert(groups.size() == 2);

    std::vector<std::string> single = {"abc"};
    assert(sol.Anagrams(single).size() == 1);

    std::vector<std::string> empty;
    assert(sol.Anagrams(empty).empty());

    std::cout << "35_Given_sequence_words_print_all_anagrams_together tests passed.\n";
    return 0;
}
