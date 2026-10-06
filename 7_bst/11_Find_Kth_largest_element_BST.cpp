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
    void reverseInorder(const Node* root, int &k, int &ans) {
        if (!root || k <= 0) return;
        reverseInorder(root->right, k, ans);
        k--;
        if (k == 0) {
            ans = root->data;
            return;
        }
        reverseInorder(root->left, k, ans);
    }

public:
    int kthLargest(const Node *root, int K) {
        int ans = -1;
        reverseInorder(root, K, ans);
        return ans;
    }
};

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(9);

    Solution sol;
    assert(sol.kthLargest(root, 1) == 9);
    assert(sol.kthLargest(root, 2) == 4);
    assert(sol.kthLargest(root, 3) == 2);

    freeTree(root);

    std::cout << "7_bst 11_Find_Kth_largest_element_BST: All tests passed.\n";
    return 0;
}
