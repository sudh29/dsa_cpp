#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        unordered_map<string, vector<string>> groups;
        for (const string &word : string_list) {
            string sortedKey = word;
            sort(sortedKey.begin(), sortedKey.end());
            groups[sortedKey].push_back(word);
        }

        vector<vector<string>> res;
        for (auto &[key, words] : groups) {
            res.push_back(words);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"act", "god", "cat", "dog", "tac"};
    auto res = sol.Anagrams(words);
    cout << "Anagram groups:\n";
    for (const auto &g : res) {
        cout << "[ ";
        for (const string &w : g) cout << w << " ";
        cout << "] ";
    }
    cout << endl;
    return 0;
}
