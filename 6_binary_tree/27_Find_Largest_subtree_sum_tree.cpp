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

class Solution {
private:
    int solve(const Node* root, int &ans) const {
        if (!root) return 0;
        int curSum = root->data + solve(root->left, ans) + solve(root->right, ans);
        ans = std::max(ans, curSum);
        return curSum;
    }

public:
    int findLargestSubtreeSum(const Node* root) const {
        if (!root) return 0;
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);

    Solution sol;
    // Subtree rooted at -2: -2 + 4 + 5 = 7
    // Subtree rooted at 3: 3 + (-6) + 2 = -1
    // Entire tree: 1 + 7 + (-1) = 7
    assert(sol.findLargestSubtreeSum(root) == 7);
    assert(sol.findLargestSubtreeSum(nullptr) == 0);

    freeTree(root);

    std::cout << "6_binary_tree 27_Find_Largest_subtree_sum_tree: All tests passed.\n";
    return 0;
}
