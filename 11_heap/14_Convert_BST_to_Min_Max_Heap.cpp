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

void inorder(const Node* root, std::vector<int> &nodes) {
    if (!root) return;
    inorder(root->left, nodes);
    nodes.push_back(root->data);
    inorder(root->right, nodes);
}

void BSTToMinHeap(Node* root, const std::vector<int> &nodes, size_t &idx) {
    if (!root) return;
    root->data = nodes[idx++];
    BSTToMinHeap(root->left, nodes, idx);
    BSTToMinHeap(root->right, nodes, idx);
}

void getPreorder(const Node* root, std::vector<int> &res) {
    if (!root) return;
    res.push_back(root->data);
    getPreorder(root->left, res);
    getPreorder(root->right, res);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    std::vector<int> nodes;
    inorder(root, nodes);
    size_t idx = 0;
    BSTToMinHeap(root, nodes, idx);

    std::vector<int> preorderRes;
    getPreorder(root, preorderRes);

    // BST inorder was 1, 2, 3, 4, 6
    // Min heap filled in preorder with sorted elements:
    // root = 1, left = 2, right = 4, left->left = 3, left->right = 6
    std::vector<int> expected = {1, 2, 3, 4, 6};
    assert(preorderRes == expected);

    freeTree(root);

    std::cout << "11_heap 14_Convert_BST_to_Min_Max_Heap: All tests passed.\n";
    return 0;
}
