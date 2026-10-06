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

bool searchElement(const Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return searchElement(root->left, key) || searchElement(root->right, key);
}

int main() {
    assert(!searchElement(nullptr, 10));

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    assert(searchElement(root, 20));
    assert(searchElement(root, 10));
    assert(searchElement(root, 30));
    assert(!searchElement(root, 50));

    freeTree(root);

    std::cout << "6_binary_tree 40_search_element_binary_tree: All tests passed.\n";
    return 0;
}
