#include <algorithm>
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

class Solution {
public:
    Node* invertTree(Node* root) {
        if (!root) return nullptr;
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

void getInorder(const Node* root, std::vector<int> &res) {
    if (!root) return;
    getInorder(root->left, res);
    res.push_back(root->data);
    getInorder(root->right, res);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Solution sol;
    sol.invertTree(root);

    std::vector<int> in;
    getInorder(root, in);
    std::vector<int> expected = {3, 1, 2};
    assert(in == expected);

    freeTree(root);

    std::cout << "6_binary_tree 4_Mirror_of_a_tree: All tests passed.\n";
    return 0;
}
