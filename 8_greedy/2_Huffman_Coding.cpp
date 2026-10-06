#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode *left, *right;
    MinHeapNode(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};

void printCodes(MinHeapNode* root, string str, vector<string> &res) {
    if (!root) return;
    if (!root->left && !root->right) res.push_back(str);
    printCodes(root->left, str + "0", res);
    printCodes(root->right, str + "1", res);
}

class Solution {
public:
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minH;
        for (int i = 0; i < N; i++) minH.push(new MinHeapNode(S[i], f[i]));

        while (minH.size() > 1) {
            MinHeapNode* left = minH.top(); minH.pop();
            MinHeapNode* right = minH.top(); minH.pop();
            MinHeapNode* top = new MinHeapNode('$', left->freq + right->freq);
            top->left = left;
            top->right = right;
            minH.push(top);
        }

        vector<string> res;
        printCodes(minH.top(), "", res);
        return res;
    }
};

int main() {
    Solution sol;
    string s = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    auto codes = sol.huffmanCodes(s, f, 6);
    cout << "Huffman codes: ";
    for (const string &c : codes) cout << c << " ";
    cout << endl;
    return 0;
}
