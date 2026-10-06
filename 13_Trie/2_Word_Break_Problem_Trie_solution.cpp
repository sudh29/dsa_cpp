#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isLeaf;

    TrieNode() : isLeaf(false) {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Solution {
private:
    TrieNode* root;

    void insert(const string &word) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx]) cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->isLeaf = true;
    }

    bool search(const string &word) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx]) return false;
            cur = cur->children[idx];
        }
        return cur && cur->isLeaf;
    }

public:
    bool wordBreakHelper(const string &s, int start, vector<int> &memo) {
        if (start == (int)s.length()) return true;
        if (memo[start] != -1) return memo[start];

        for (int end = start + 1; end <= (int)s.length(); end++) {
            if (search(s.substr(start, end - start)) && wordBreakHelper(s, end, memo)) {
                memo[start] = 1;
                return true;
            }
        }
        memo[start] = 0;
        return false;
    }

    int wordBreak(int n, string s, vector<string> &dictionary) {
        root = new TrieNode();
        for (int i = 0; i < n; i++) insert(dictionary[i]);
        vector<int> memo(s.length(), -1);
        return wordBreakHelper(s, 0, memo) ? 1 : 0;
    }
};

int main() {
    Solution sol;
    vector<string> dict = {"i", "like", "sam", "sung", "samsung", "mobile"};
    int res = sol.wordBreak(dict.size(), "ilikesamsung", dict);
    cout << "Word break 'ilikesamsung': " << res << endl;
    if (res != 1) return 1;
    return 0;
}
