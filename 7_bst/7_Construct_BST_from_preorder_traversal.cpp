#include <cassert>
#include <climits>
#include <iostream>
#include <span>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

class Solution {
private:
    TreeNode* build(std::span<const int> preorder, size_t &idx, int bound) {
        if (idx == preorder.size() || preorder[idx] > bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = build(preorder, idx, root->val);
        root->right = build(preorder, idx, bound);
        return root;
    }

public:
    TreeNode* bstFromPreorder(std::span<const int> preorder) {
        size_t idx = 0;
        return build(preorder, idx, INT_MAX);
    }
};

void getInorder(const TreeNode* root, std::vector<int> &res) {
    if (!root) return;
    getInorder(root->left, res);
    res.push_back(root->val);
    getInorder(root->right, res);
}

int main() {
    Solution sol;
    std::vector<int> pre = {8, 5, 1, 7, 10, 12};
    TreeNode* root = sol.bstFromPreorder(pre);

    std::vector<int> in;
    getInorder(root, in);
    std::vector<int> expected = {1, 5, 7, 8, 10, 12};
    assert(in == expected);

    freeTree(root);

    std::cout << "7_bst 7_Construct_BST_from_preorder_traversal: All tests passed.\n";
    return 0;
}
