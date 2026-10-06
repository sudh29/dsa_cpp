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

Node* LCA(Node* root, int n1, int n2) {
    if (!root) return nullptr;
    if (root->data > n1 && root->data > n2) return LCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2) return LCA(root->right, n1, n2);
    return root;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);

    Node* lca1 = LCA(root, 4, 12);
    assert(lca1 != nullptr && lca1->data == 8);

    Node* lca2 = LCA(root, 4, 22);
    assert(lca2 != nullptr && lca2->data == 20);

    Node* lca3 = LCA(root, 8, 12);
    assert(lca3 != nullptr && lca3->data == 8);

    freeTree(root);

    std::cout << "7_bst 6_Find_LCA_2_nodes_BST: All tests passed.\n";
    return 0;
}
