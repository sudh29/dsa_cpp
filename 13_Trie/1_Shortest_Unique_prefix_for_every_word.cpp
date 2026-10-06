#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    int freq;

    TrieNode() : freq(0) {
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
            cur->freq++;
        }
    }

    string findPrefix(const string &word) {
        TrieNode* cur = root;
        string prefix = "";
        for (char c : word) {
            prefix += c;
            cur = cur->children[c - 'a'];
            if (cur->freq == 1) break;
        }
        return prefix;
    }

public:
    vector<string> findPrefixes(string arr[], int n) {
        root = new TrieNode();
        for (int i = 0; i < n; i++) insert(arr[i]);

        vector<string> res;
        for (int i = 0; i < n; i++) {
            res.push_back(findPrefix(arr[i]));
        }
        return res;
    }
};

int main() {
    string words[] = {"zebra", "dog", "duck", "dove"};
    Solution sol;
    auto prefixes = sol.findPrefixes(words, 4);
    cout << "Shortest unique prefixes: ";
    for (const string &p : prefixes) cout << p << " ";
    cout << endl;
    return 0;
}
