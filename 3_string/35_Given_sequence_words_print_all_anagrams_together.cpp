#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        unordered_map<string, vector<string>> mp;
        for (const string &s : string_list) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto &[key, group] : mp) {
            res.push_back(group);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"act", "god", "cat", "dog", "tac"};
    auto groups = sol.Anagrams(words);
    cout << "Anagram groups:\n";
    for (const auto &g : groups) {
        cout << "[ ";
        for (const string &w : g) cout << w << " ";
        cout << "] ";
    }
    cout << endl;
    return 0;
}
