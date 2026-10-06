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

bool findPath(const Node* root, int target, std::vector<int> &path) {
    if (!root) return false;
    path.push_back(root->data);
    if (root->data == target) return true;
    if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
        return true;
    }
    path.pop_back();
    return false;
}

int kthAncestor(const Node *root, int k, int node) {
    if (k < 0) return -1;
    std::vector<int> path;
    if (!findPath(root, node, path)) return -1;
    int idx = static_cast<int>(path.size()) - 1 - k;
    return (idx >= 0) ? path[idx] : -1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    assert(kthAncestor(root, 1, 4) == 2);
    assert(kthAncestor(root, 2, 4) == 1);
    assert(kthAncestor(root, 3, 4) == -1);
    assert(kthAncestor(root, 1, 1) == -1);
    assert(kthAncestor(root, 1, 99) == -1);

    freeTree(root);

    std::cout << "6_binary_tree 32_Kth_Ancestor_node_Binary_tree: All tests passed.\n";
    return 0;
}
