#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>

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
    int checkHeight(const Node* root) const {
        if (!root) return 0;
        int lh = checkHeight(root->left);
        if (lh == -1) return -1;
        int rh = checkHeight(root->right);
        if (rh == -1) return -1;
        if (std::abs(lh - rh) > 1) return -1;
        return 1 + std::max(lh, rh);
    }

public:
    bool isBalanced(const Node *root) const {
        return checkHeight(root) != -1;
    }
};

int main() {
    Solution sol;
    assert(sol.isBalanced(nullptr));

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    assert(sol.isBalanced(root));

    // Make unbalanced
    root->left->left->left = new Node(5);
    assert(!sol.isBalanced(root));

    freeTree(root);

    std::cout << "6_binary_tree 13_Check_tree_balanced_or_not: All tests passed.\n";
    return 0;
}
