#include <iostream>
#include <vector>

using namespace std;

struct TrieNode {
    TrieNode* children[2];
    bool isLeaf;
    TrieNode() : isLeaf(false) {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Solution {
public:
    bool insertRow(TrieNode* root, const vector<int> &row) {
        TrieNode* cur = root;
        for (int bit : row) {
            if (!cur->children[bit]) cur->children[bit] = new TrieNode();
            cur = cur->children[bit];
        }
        if (cur->isLeaf) return false;
        cur->isLeaf = true;
        return true;
    }

    vector<vector<int>> uniqueRow(int row, int col, vector<vector<int>> M) {
        (void)col;
        TrieNode* root = new TrieNode();
        vector<vector<int>> res;

        for (int i = 0; i < row; i++) {
            if (insertRow(root, M[i])) {
                res.push_back(M[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 1, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 1}
    };
    auto uniq = sol.uniqueRow(3, 4, mat);
    cout << "Unique rows count: " << uniq.size() << endl; // 2
    if (uniq.size() != 2) return 1;
    return 0;
}
