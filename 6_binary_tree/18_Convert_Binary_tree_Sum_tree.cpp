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
    int toSumTreeUtil(Node* root) {
        if (!root) return 0;
        int oldVal = root->data;
        root->data = toSumTreeUtil(root->left) + toSumTreeUtil(root->right);
        return root->data + oldVal;
    }

public:
    void toSumTree(Node *node) {
        toSumTreeUtil(node);
    }
};

void getInorder(const Node* root, std::vector<int> &res) {
    if (!root) return;
    getInorder(root->left, res);
    res.push_back(root->data);
    getInorder(root->right, res);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    Solution sol;
    sol.toSumTree(root);

    std::vector<int> in;
    getInorder(root, in);
    // Inorder of tree:
    // 8 becomes 0
    // -2 becomes 8 + (-4) = 4
    // -4 becomes 0
    // 10 becomes (-2+8-4) + (6+7+5) = 2 + 18 = 20
    // 7 becomes 0
    // 6 becomes 7 + 5 = 12
    // 5 becomes 0
    std::vector<int> expected = {0, 4, 0, 20, 0, 12, 0};
    assert(in == expected);

    freeTree(root);

    std::cout << "6_binary_tree 18_Convert_Binary_tree_Sum_tree: All tests passed.\n";
    return 0;
}
