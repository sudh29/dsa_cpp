#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* build(const vector<int> &preorder, int &idx, int bound) {
        if (idx == (int)preorder.size() || preorder[idx] > bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = build(preorder, idx, root->val);
        root->right = build(preorder, idx, bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return build(preorder, idx, INT_MAX);
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;
    vector<int> pre = {8, 5, 1, 7, 10, 12};
    TreeNode* root = sol.bstFromPreorder(pre);
    cout << "Inorder of constructed BST: ";
    inorder(root);
    cout << endl;
    return 0;
}
