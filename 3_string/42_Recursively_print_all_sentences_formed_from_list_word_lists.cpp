#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backtrack(const vector<vector<string>> &L, size_t row, vector<string> &current, vector<vector<string>> &res) {
        if (row == L.size()) {
            res.push_back(current);
            return;
        }
        for (const string &word : L[row]) {
            current.push_back(word);
            backtrack(L, row + 1, current, res);
            current.pop_back();
        }
    }

    vector<vector<string>> sentences(vector<vector<string>>& L) {
        vector<vector<string>> res;
        vector<string> current;
        backtrack(L, 0, current, res);
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> words = {
        {"you", "we"},
        {"have", "are"},
        {"sleep", "eat"}
    };
    auto sentences = sol.sentences(words);
    cout << "Generated sentences:\n";
    for (const auto &s : sentences) {
        for (const string &w : s) cout << w << " ";
        cout << endl;
    }
    return 0;
}
