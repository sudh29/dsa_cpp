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

int minValue(const Node* root) {
    if (!root) return -1;
    const Node* cur = root;
    while (cur->left) cur = cur->left;
    return cur->data;
}

int maxValue(const Node* root) {
    if (!root) return -1;
    const Node* cur = root;
    while (cur->right) cur = cur->right;
    return cur->data;
}

int main() {
    assert(minValue(nullptr) == -1);
    assert(maxValue(nullptr) == -1);

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->right->right = new Node(12);

    assert(minValue(root) == 1);
    assert(maxValue(root) == 12);

    freeTree(root);

    std::cout << "7_bst 2_Find_min_and_max_value_BST: All tests passed.\n";
    return 0;
}
