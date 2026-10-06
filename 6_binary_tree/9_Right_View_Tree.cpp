#include <cassert>
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

class Solution {
private:
    void rightViewUtil(const Node* root, int level, int &maxLevel, std::vector<int> &res) const {
        if (!root) return;
        if (maxLevel < level) {
            res.push_back(root->data);
            maxLevel = level;
        }
        rightViewUtil(root->right, level + 1, maxLevel, res);
        rightViewUtil(root->left, level + 1, maxLevel, res);
    }

public:
    std::vector<int> rightView(const Node *root) const {
        std::vector<int> res;
        int maxLevel = 0;
        rightViewUtil(root, 1, maxLevel, res);
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    Solution sol;
    auto res = sol.rightView(root);
    std::vector<int> expected = {1, 3, 4};
    assert(res == expected);

    assert(sol.rightView(nullptr).empty());

    freeTree(root);

    std::cout << "6_binary_tree 9_Right_View_Tree: All tests passed.\n";
    return 0;
}
