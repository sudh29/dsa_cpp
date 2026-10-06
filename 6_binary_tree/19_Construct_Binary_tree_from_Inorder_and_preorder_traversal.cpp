#include <cassert>
#include <iostream>
#include <span>
#include <unordered_map>
#include <vector>

struct Node {
    int data;
    Node* left;
    Node* right;
    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

class Solution {
private:
    Node* build(std::span<const int> in, std::span<const int> pre,
                int inStart, int inEnd, size_t &preIdx,
                const std::unordered_map<int, int> &inMap) {
        if (inStart > inEnd || preIdx >= pre.size()) return nullptr;
        int rootVal = pre[preIdx++];
        Node* root = new Node(rootVal);
        int inIndex = inMap.at(rootVal);

        root->left = build(in, pre, inStart, inIndex - 1, preIdx, inMap);
        root->right = build(in, pre, inIndex + 1, inEnd, preIdx, inMap);
        return root;
    }

public:
    Node* buildTree(std::span<const int> in, std::span<const int> pre) {
        std::unordered_map<int, int> inMap;
        for (size_t i = 0; i < in.size(); ++i) {
            inMap[in[i]] = static_cast<int>(i);
        }
        size_t preIdx = 0;
        return build(in, pre, 0, static_cast<int>(in.size()) - 1, preIdx, inMap);
    }
};

void getPostorder(const Node* root, std::vector<int> &res) {
    if (!root) return;
    getPostorder(root->left, res);
    getPostorder(root->right, res);
    res.push_back(root->data);
}

int main() {
    std::vector<int> in = {3, 1, 4, 0, 5, 2};
    std::vector<int> pre = {0, 1, 3, 4, 2, 5};
    Solution sol;
    Node* root = sol.buildTree(in, pre);

    std::vector<int> post;
    getPostorder(root, post);
    std::vector<int> expected = {3, 4, 1, 5, 2, 0};
    assert(post == expected);

    freeTree(root);

    std::cout << "6_binary_tree 19_Construct_Binary_tree_from_Inorder_and_preorder_traversal: All tests passed.\n";
    return 0;
}
