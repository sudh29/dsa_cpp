#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(const string &key) {
        TrieNode* cur = root;
        for (char c : key) {
            int idx = c - 'a';
            if (!cur->children[idx]) cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->isEndOfWord = true;
    }

    bool search(const string &key) {
        TrieNode* cur = root;
        for (char c : key) {
            int idx = c - 'a';
            if (!cur->children[idx]) return false;
            cur = cur->children[idx];
        }
        return (cur != nullptr && cur->isEndOfWord);
    }
};

int main() {
    Trie trie;
    trie.insert("the");
    trie.insert("there");
    trie.insert("any");

    cout << "Search 'the': " << (trie.search("the") ? "Found" : "Not Found") << endl;
    cout << "Search 'these': " << (trie.search("these") ? "Found" : "Not Found") << endl;
    return 0;
}
