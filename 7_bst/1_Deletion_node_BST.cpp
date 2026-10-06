#include <cassert>
#include <iostream>
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
public:
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};

void getInorder(const TreeNode* root, std::vector<int> &res) {
    if (!root) return;
    getInorder(root->left, res);
    res.push_back(root->val);
    getInorder(root->right, res);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    Solution sol;
    root = sol.deleteNode(root, 3);

    std::vector<int> vals;
    getInorder(root, vals);
    std::vector<int> expected = {2, 4, 5, 6};
    assert(vals == expected);

    // Delete root node 5
    root = sol.deleteNode(root, 5);
    vals.clear();
    getInorder(root, vals);
    expected = {2, 4, 6};
    assert(vals == expected);

    freeTree(root);

    std::cout << "7_bst 1_Deletion_node_BST: All tests passed.\n";
    return 0;
}
