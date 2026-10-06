#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <queue>

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

int maxLevelSum(const Node* root) {
    if (!root) return 0;
    std::queue<const Node*> q;
    q.push(root);
    int maxSum = INT_MIN;

    while (!q.empty()) {
        size_t sz = q.size();
        int levelSum = 0;
        for (size_t i = 0; i < sz; ++i) {
            const Node* cur = q.front();
            q.pop();
            levelSum += cur->data;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        maxSum = std::max(maxSum, levelSum);
    }
    return maxSum;
}

int main() {
    assert(maxLevelSum(nullptr) == 0);

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);

    // Level 0: 1
    // Level 1: 2 + 3 = 5
    // Level 2: 4 + 5 + 8 = 17
    assert(maxLevelSum(root) == 17);

    freeTree(root);

    std::cout << "6_binary_tree 38_max_sum_level_binary_tree: All tests passed.\n";
    return 0;
}
