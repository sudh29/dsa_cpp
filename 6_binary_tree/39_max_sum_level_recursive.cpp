#include <algorithm>
#include <cassert>
#include <climits>
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

void calculateLevelSums(const Node* root, size_t level, std::vector<int> &sums) {
    if (!root) return;
    if (level == sums.size()) {
        sums.push_back(0);
    }
    sums[level] += root->data;
    calculateLevelSums(root->left, level + 1, sums);
    calculateLevelSums(root->right, level + 1, sums);
}

int maxLevelSumRec(const Node* root) {
    if (!root) return 0;
    std::vector<int> sums;
    calculateLevelSums(root, 0, sums);
    int maxSum = INT_MIN;
    for (int s : sums) {
        maxSum = std::max(maxSum, s);
    }
    return maxSum;
}

int main() {
    assert(maxLevelSumRec(nullptr) == 0);

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(-5);
    root->left->left = new Node(-1);
    root->left->right = new Node(3);

    // Level 0: 4
    // Level 1: 2 + (-5) = -3
    // Level 2: (-1) + 3 = 2
    // Max level sum: 4
    assert(maxLevelSumRec(root) == 4);

    freeTree(root);

    std::cout << "6_binary_tree 39_max_sum_level_recursive: All tests passed.\n";
    return 0;
}
