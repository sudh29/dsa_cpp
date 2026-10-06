#include <algorithm>
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
    void solve(const Node* root, int len, int sum, int &maxLen, int &maxSum) const {
        if (!root) return;
        sum += root->data;
        if (!root->left && !root->right) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            } else if (len == maxLen) {
                maxSum = std::max(maxSum, sum);
            }
            return;
        }
        solve(root->left, len + 1, sum, maxLen, maxSum);
        solve(root->right, len + 1, sum, maxLen, maxSum);
    }

public:
    int sumOfLongRootToLeafPath(const Node *root) const {
        if (!root) return 0;
        int maxLen = 0;
        int maxSum = 0;
        solve(root, 1, 0, maxLen, maxSum);
        return maxSum;
    }
};

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->right->left = new Node(2);
    root->right->right = new Node(3);
    root->left->right->left = new Node(6);

    Solution sol;
    // Longest path: 4 -> 2 -> 1 -> 6 (length 4), sum = 4 + 2 + 1 + 6 = 13
    assert(sol.sumOfLongRootToLeafPath(root) == 13);
    assert(sol.sumOfLongRootToLeafPath(nullptr) == 0);

    freeTree(root);

    std::cout << "6_binary_tree 25_Sum_Nodes_Longest_path_from_root_leaf_node: All tests passed.\n";
    return 0;
}
