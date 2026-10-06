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
    void postorderHelper(const Node* root, std::vector<int> &res) const {
        if (!root) return;
        postorderHelper(root->left, res);
        postorderHelper(root->right, res);
        res.push_back(root->data);
    }

public:
    std::vector<int> postorderTraversal(const Node* root) const {
        std::vector<int> res;
        postorderHelper(root, res);
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->left = new Node(3);

    Solution sol;
    auto res = sol.postorderTraversal(root);
    std::vector<int> expected = {3, 2, 1};
    assert(res == expected);

    assert(sol.postorderTraversal(nullptr).empty());

    freeTree(root);

    std::cout << "6_binary_tree 7_Postorder_Traversal: All tests passed.\n";
    return 0;
}
