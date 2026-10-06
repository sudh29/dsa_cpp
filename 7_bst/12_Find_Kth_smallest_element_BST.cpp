#include <cassert>
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

class Solution {
private:
    void inorder(const Node* root, int &k, int &ans) {
        if (!root || k <= 0) return;
        inorder(root->left, k, ans);
        k--;
        if (k == 0) {
            ans = root->data;
            return;
        }
        inorder(root->right, k, ans);
    }

public:
    int KthSmallestElement(const Node *root, int K) {
        int ans = -1;
        inorder(root, K, ans);
        return ans;
    }
};

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(9);
    root->left->left = new Node(1);

    Solution sol;
    assert(sol.KthSmallestElement(root, 1) == 1);
    assert(sol.KthSmallestElement(root, 2) == 2);
    assert(sol.KthSmallestElement(root, 3) == 4);
    assert(sol.KthSmallestElement(root, 4) == 9);

    freeTree(root);

    std::cout << "7_bst 12_Find_Kth_smallest_element_BST: All tests passed.\n";
    return 0;
}
