#include <cassert>
#include <climits>
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
    bool isBSTUtil(const Node* root, long long minVal, long long maxVal) const {
        if (!root) return true;
        if (root->data <= minVal || root->data >= maxVal) return false;
        return isBSTUtil(root->left, minVal, root->data) &&
               isBSTUtil(root->right, root->data, maxVal);
    }

public:
    bool isBST(const Node* root) const {
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    Solution sol;
    assert(sol.isBST(root));

    // Invalidate BST
    root->left->data = 5;
    assert(!sol.isBST(root));

    freeTree(root);

    std::cout << "7_bst 4_Check_if_tree_BST_or_not: All tests passed.\n";
    return 0;
}
