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
    Node* lca(Node* root, int n1, int n2) {
        if (!root) return nullptr;
        if (root->data == n1 || root->data == n2) return root;

        Node* left = lca(root->left, n1, n2);
        Node* right = lca(root->right, n1, n2);

        if (left && right) return root;
        return left ? left : right;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    Node* ans1 = sol.lca(root, 4, 5);
    assert(ans1 != nullptr && ans1->data == 2);

    Node* ans2 = sol.lca(root, 4, 3);
    assert(ans2 != nullptr && ans2->data == 1);

    freeTree(root);

    std::cout << "6_binary_tree 30_Find_LCA_Binary_tree: All tests passed.\n";
    return 0;
}
