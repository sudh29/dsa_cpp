#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    void backtrack(const std::vector<std::vector<std::string>>& L, size_t row,
                   std::vector<std::string>& current, std::vector<std::vector<std::string>>& res) {
        if (row == L.size()) {
            res.push_back(current);
            return;
        }
        for (const std::string& word : L[row]) {
            current.push_back(word);
            backtrack(L, row + 1, current, res);
            current.pop_back();
        }
    }

    std::vector<std::vector<std::string>> sentences(const std::vector<std::vector<std::string>>& L) {
        std::vector<std::vector<std::string>> res;
        if (L.empty()) return res;
        std::vector<std::string> current;
        backtrack(L, 0, current, res);
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::string>> words = {
        {"you", "we"},
        {"have", "are"},
        {"sleep", "eat"}
    };
    auto sentences = sol.sentences(words);
    assert(sentences.size() == 8);

    std::vector<std::string> first = {"you", "have", "sleep"};
    std::vector<std::string> last = {"we", "are", "eat"};
    assert(sentences.front() == first);
    assert(sentences.back() == last);

    std::vector<std::vector<std::string>> empty;
    assert(sol.sentences(empty).empty());

    std::cout << "42_Recursively_print_all_sentences_formed_from_list_word_lists tests passed.\n";
    return 0;
}
