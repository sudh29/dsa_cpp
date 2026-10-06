#include <algorithm>
#include <cassert>
#include <iostream>
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
    void inorderExtract(const Node* root, std::vector<int> &nodes) {
        if (!root) return;
        inorderExtract(root->left, nodes);
        nodes.push_back(root->data);
        inorderExtract(root->right, nodes);
    }

    void inorderFill(Node* root, const std::vector<int> &nodes, size_t &idx) {
        if (!root) return;
        inorderFill(root->left, nodes, idx);
        root->data = nodes[idx++];
        inorderFill(root->right, nodes, idx);
    }

public:
    Node* binaryTreeToBST(Node* root) {
        std::vector<int> nodes;
        inorderExtract(root, nodes);
        std::sort(nodes.begin(), nodes.end());
        size_t idx = 0;
        inorderFill(root, nodes, idx);
        return root;
    }
};

void getInorder(const Node* root, std::vector<int> &res) {
    if (!root) return;
    getInorder(root->left, res);
    res.push_back(root->data);
    getInorder(root->right, res);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Solution sol;
    sol.binaryTreeToBST(root);

    std::vector<int> in;
    getInorder(root, in);
    std::vector<int> expected = {1, 2, 3};
    assert(in == expected);

    freeTree(root);

    std::cout << "7_bst 8_Convert_Binary_tree_into_BST: All tests passed.\n";
    return 0;
}
