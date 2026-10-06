#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    set<string> contacts;

    TrieNode() {
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
            cur->contacts.insert(word);
        }
    }

public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        root = new TrieNode();
        for (int i = 0; i < n; i++) insert(contact[i]);

        vector<vector<string>> res;
        TrieNode* cur = root;
        bool missing = false;

        for (char c : s) {
            int idx = c - 'a';
            if (!missing && cur && cur->children[idx]) {
                cur = cur->children[idx];
                vector<string> matches(cur->contacts.begin(), cur->contacts.end());
                res.push_back(matches);
            } else {
                missing = true;
                res.push_back({"0"});
            }
        }
        return res;
    }
};

int main() {
    string contacts[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    Solution sol;
    auto res = sol.displayContacts(3, contacts, "gee");
    cout << "Contacts matching prefix 'gee':\n";
    for (const string &c : res.back()) cout << "  " << c << endl;
    return 0;
}
