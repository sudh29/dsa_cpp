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
public:
    int getCount(const Node *root, int l, int h) const {
        if (!root) return 0;
        if (root->data >= l && root->data <= h) {
            return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
        } else if (root->data < l) {
            return getCount(root->right, l, h);
        } else {
            return getCount(root->left, l, h);
        }
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    Solution sol;
    // Nodes in range [5, 45]: 5, 10, 40 (count = 3)
    assert(sol.getCount(root, 5, 45) == 3);
    assert(sol.getCount(root, 1, 100) == 6);
    assert(sol.getCount(root, 50, 100) == 2);
    assert(sol.getCount(root, 200, 300) == 0);

    freeTree(root);

    std::cout << "7_bst 15_Count_BST_nodes_lie_range: All tests passed.\n";
    return 0;
}
