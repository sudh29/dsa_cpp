#include <cassert>
#include <cmath>
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

void inorder(const Node* root, std::vector<int> &v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

float findMedian(const Node *root) {
    std::vector<int> v;
    inorder(root, v);
    size_t n = v.size();
    if (n == 0) return 0.0f;
    if (n % 2 != 0) return static_cast<float>(v[n / 2]);
    return (v[(n / 2) - 1] + v[n / 2]) / 2.0f;
}

int main() {
    assert(std::abs(findMedian(nullptr) - 0.0f) < 1e-6);

    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    // Inorder: 1, 3, 4, 6, 8 (odd length 5, median is 4)
    assert(std::abs(findMedian(root) - 4.0f) < 1e-6);

    // Add node 7: Inorder: 1, 3, 4, 6, 7, 8 (even length 6, median is (4 + 6) / 2 = 5.0)
    root->right->left = new Node(7);
    assert(std::abs(findMedian(root) - 5.0f) < 1e-6);

    freeTree(root);

    std::cout << "7_bst 14_Find_the_median_BST: All tests passed.\n";
    return 0;
}
