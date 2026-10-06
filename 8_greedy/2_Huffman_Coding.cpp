#include <cassert>
#include <iostream>
#include <queue>
#include <span>
#include <string>
#include <string_view>
#include <vector>

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

void freeTree(MinHeapNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void printCodes(MinHeapNode* root, std::string str, std::vector<std::string>& res) {
    if (!root) return;
    if (!root->left && !root->right) res.push_back(str);
    printCodes(root->left, str + "0", res);
    printCodes(root->right, str + "1", res);
}

class Solution {
public:
    std::vector<std::string> huffmanCodes(std::string_view S, std::span<const int> f) {
        size_t N = S.length();
        if (N == 0) return {};
        std::priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, compare> minH;
        for (size_t i = 0; i < N; i++) {
            minH.push(new MinHeapNode(S[i], f[i]));
        }

        while (minH.size() > 1) {
            MinHeapNode* left = minH.top(); minH.pop();
            MinHeapNode* right = minH.top(); minH.pop();
            MinHeapNode* top = new MinHeapNode('$', left->freq + right->freq);
            top->left = left;
            top->right = right;
            minH.push(top);
        }

        std::vector<std::string> res;
        MinHeapNode* root = minH.top();
        printCodes(root, "", res);
        freeTree(root);
        return res;
    }
};

int main() {
    Solution sol;
    std::string_view s = "abcdef";
    std::vector<int> f = {5, 9, 12, 13, 16, 45};
    auto codes = sol.huffmanCodes(s, f);
    assert(codes.size() == 6);
    for (const auto& c : codes) {
        assert(!c.empty());
    }
    // Verify prefix-free code property
    for (size_t i = 0; i < codes.size(); i++) {
        for (size_t j = 0; j < codes.size(); j++) {
            if (i != j) {
                assert(codes[i].find(codes[j]) != 0);
            }
        }
    }

    std::cout << "2_Huffman_Coding tests passed.\n";
    return 0;
}
