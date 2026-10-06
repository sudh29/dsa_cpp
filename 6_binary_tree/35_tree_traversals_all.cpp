#include <cassert>
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

void inorder(const Node* root, std::vector<int> &res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}

void preorder(const Node* root, std::vector<int> &res) {
    if (!root) return;
    res.push_back(root->data);
    preorder(root->left, res);
    preorder(root->right, res);
}

void postorder(const Node* root, std::vector<int> &res) {
    if (!root) return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->data);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    std::vector<int> in;
    inorder(root, in);
    std::vector<int> inExp = {2, 1, 3};
    assert(in == inExp);

    std::vector<int> pre;
    preorder(root, pre);
    std::vector<int> preExp = {1, 2, 3};
    assert(pre == preExp);

    std::vector<int> post;
    postorder(root, post);
    std::vector<int> postExp = {2, 3, 1};
    assert(post == postExp);

    freeTree(root);

    std::cout << "6_binary_tree 35_tree_traversals_all: All tests passed.\n";
    return 0;
}
