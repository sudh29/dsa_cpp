#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>

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

struct NodeInfo {
    int size;
    int maxVal;
    int minVal;
    int ans;
    bool isBST;
};

class Solution {
private:
    NodeInfo largestBSTUtil(const Node* root) {
        if (!root) return {0, INT_MIN, INT_MAX, 0, true};
        if (!root->left && !root->right) return {1, root->data, root->data, 1, true};

        NodeInfo l = largestBSTUtil(root->left);
        NodeInfo r = largestBSTUtil(root->right);

        NodeInfo ret;
        ret.size = 1 + l.size + r.size;

        if (l.isBST && r.isBST && l.maxVal < root->data && r.minVal > root->data) {
            ret.minVal = std::min(root->data, l.minVal);
            ret.maxVal = std::max(root->data, r.maxVal);
            ret.ans = ret.size;
            ret.isBST = true;
            return ret;
        }

        ret.ans = std::max(l.ans, r.ans);
        ret.isBST = false;
        return ret;
    }

public:
    int largestBst(const Node *root) {
        return largestBSTUtil(root).ans;
    }
};

int main() {
    Node* root = new Node(6);
    root->left = new Node(6);
    root->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(9);

    Solution sol;
    // Subtree rooted at 3 has 2 (left) and 9 (right), valid BST of size 3
    assert(sol.largestBst(root) == 3);

    freeTree(root);

    std::cout << "7_bst 20_Largest_BST_Binary_Tree: All tests passed.\n";
    return 0;
}
