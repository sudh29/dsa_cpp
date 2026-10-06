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

class BST {
public:
    bool search(const Node* root, int x) const {
        if (!root) return false;
        if (root->data == x) return true;
        if (x < root->data) return search(root->left, x);
        return search(root->right, x);
    }
};

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    BST bst;
    assert(bst.search(root, 3));
    assert(bst.search(root, 1));
    assert(bst.search(root, 7));
    assert(bst.search(root, 4));
    assert(!bst.search(root, 5));
    assert(!bst.search(root, 0));
    assert(!bst.search(root, 10));

    freeTree(root);

    std::cout << "7_bst 0_Find_value_BST: All tests passed.\n";
    return 0;
}
