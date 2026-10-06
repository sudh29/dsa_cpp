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
    int checkSumTree(const Node* root) const {
        if (!root) return 0;
        if (!root->left && !root->right) return root->data;

        int ls = checkSumTree(root->left);
        if (ls == -1) return -1;
        int rs = checkSumTree(root->right);
        if (rs == -1) return -1;

        if (root->data == ls + rs) {
            return 2 * root->data;
        }
        return -1;
    }

public:
    bool isSumTree(const Node* root) const {
        return checkSumTree(root) != -1;
    }
};

int main() {
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    Solution sol;
    assert(sol.isSumTree(root));

    // Violate sum tree property
    root->data = 30;
    assert(!sol.isSumTree(root));

    freeTree(root);

    std::cout << "6_binary_tree 21_Check_if_Binary_tree_is_Sum_tree_or_not: All tests passed.\n";
    return 0;
}
