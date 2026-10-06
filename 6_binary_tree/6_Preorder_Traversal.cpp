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
    void preorderHelper(const Node* root, std::vector<int> &res) const {
        if (!root) return;
        res.push_back(root->data);
        preorderHelper(root->left, res);
        preorderHelper(root->right, res);
    }

public:
    std::vector<int> preorderTraversal(const Node* root) const {
        std::vector<int> res;
        preorderHelper(root, res);
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->left = new Node(3);

    Solution sol;
    auto res = sol.preorderTraversal(root);
    std::vector<int> expected = {1, 2, 3};
    assert(res == expected);

    assert(sol.preorderTraversal(nullptr).empty());

    freeTree(root);

    std::cout << "6_binary_tree 6_Preorder_Traversal: All tests passed.\n";
    return 0;
}
