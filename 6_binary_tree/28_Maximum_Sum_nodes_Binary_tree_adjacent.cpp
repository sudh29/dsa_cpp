#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>

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
    // returns {including_root, excluding_root}
    std::pair<int, int> dfs(const Node* root) const {
        if (!root) return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);

        int incl = root->data + l.second + r.second;
        int excl = std::max(l.first, l.second) + std::max(r.first, r.second);
        return {incl, excl};
    }

public:
    int getMaxSum(const Node *root) const {
        auto res = dfs(root);
        return std::max(res.first, res.second);
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    Solution sol;
    // Optimal: choose nodes 1, 4, 5 (from bottom) and root 1 = 1 + 1 + 4 + 5 = 11
    assert(sol.getMaxSum(root) == 11);
    assert(sol.getMaxSum(nullptr) == 0);

    freeTree(root);

    std::cout << "6_binary_tree 28_Maximum_Sum_nodes_Binary_tree_adjacent: All tests passed.\n";
    return 0;
}
