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

void leftViewUtil(const Node* root, int level, int &maxLevel, std::vector<int> &res) {
    if (!root) return;
    if (maxLevel < level) {
        res.push_back(root->data);
        maxLevel = level;
    }
    leftViewUtil(root->left, level + 1, maxLevel, res);
    leftViewUtil(root->right, level + 1, maxLevel, res);
}

std::vector<int> leftView(const Node *root) {
    std::vector<int> res;
    int maxLevel = 0;
    leftViewUtil(root, 1, maxLevel, res);
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    auto res = leftView(root);
    std::vector<int> expected = {1, 2, 4};
    assert(res == expected);

    assert(leftView(nullptr).empty());

    freeTree(root);

    std::cout << "6_binary_tree 8_Left_View_tree: All tests passed.\n";
    return 0;
}
