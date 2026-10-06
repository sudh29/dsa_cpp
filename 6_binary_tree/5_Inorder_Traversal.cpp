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
private:
    void inorderHelper(const Node* root, std::vector<int> &res) const {
        if (!root) return;
        inorderHelper(root->left, res);
        res.push_back(root->data);
        inorderHelper(root->right, res);
    }

public:
    std::vector<int> inorderTraversal(const Node* root) const {
        std::vector<int> res;
        inorderHelper(root, res);
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->left = new Node(3);

    Solution sol;
    auto res = sol.inorderTraversal(root);
    std::vector<int> expected = {1, 3, 2};
    assert(res == expected);

    assert(sol.inorderTraversal(nullptr).empty());

    freeTree(root);

    std::cout << "6_binary_tree 5_Inorder_Traversal: All tests passed.\n";
    return 0;
}
