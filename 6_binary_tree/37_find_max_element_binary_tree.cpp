#include <algorithm>
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

int findMax(const Node* root) {
    if (!root) return INT_MIN;
    return std::max({root->data, findMax(root->left), findMax(root->right)});
}

int main() {
    assert(findMax(nullptr) == INT_MIN);

    Node* root = new Node(2);
    root->left = new Node(7);
    root->right = new Node(5);
    root->left->right = new Node(6);
    root->left->right->left = new Node(11);

    assert(findMax(root) == 11);

    freeTree(root);

    std::cout << "6_binary_tree 37_find_max_element_binary_tree: All tests passed.\n";
    return 0;
}
