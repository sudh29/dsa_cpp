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
    bool checkLevel(const Node* root, int level, int &leafLevel) const {
        if (!root) return true;
        if (!root->left && !root->right) {
            if (leafLevel == 0) {
                leafLevel = level;
                return true;
            }
            return (level == leafLevel);
        }
        return checkLevel(root->left, level + 1, leafLevel) &&
               checkLevel(root->right, level + 1, leafLevel);
    }

public:
    bool check(const Node *root) const {
        int leafLevel = 0;
        return checkLevel(root, 1, leafLevel);
    }
};

int main() {
    Solution sol;
    assert(sol.check(nullptr));

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    assert(sol.check(root));

    // Add leaf at different level
    root->left->left->left = new Node(6);
    assert(!sol.check(root));

    freeTree(root);

    std::cout << "6_binary_tree 22_Leaf_at_same_leve: All tests passed.\n";
    return 0;
}
