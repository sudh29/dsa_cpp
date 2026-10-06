#include <algorithm>
#include <cassert>
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
public:
    int height(const Node* node) const {
        if (!node) return 0;
        return 1 + std::max(height(node->left), height(node->right));
    }
};

int main() {
    Solution sol;
    assert(sol.height(nullptr) == 0);

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    assert(sol.height(root) == 3);

    freeTree(root);

    std::cout << "6_binary_tree 2_Height_of_a_tree: All tests passed.\n";
    return 0;
}
