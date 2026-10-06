#include <cassert>
#include <iostream>
#include <span>
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
    void inorder(Node* root, std::vector<Node*> &nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

    Node* buildBalanced(std::span<Node*> nodes, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        Node* root = nodes[mid];
        root->left = buildBalanced(nodes, start, mid - 1);
        root->right = buildBalanced(nodes, mid + 1, end);
        return root;
    }

public:
    Node* buildBalancedTree(Node* root) {
        std::vector<Node*> nodes;
        inorder(root, nodes);
        return buildBalanced(nodes, 0, static_cast<int>(nodes.size()) - 1);
    }
};

void getPreorder(const Node* root, std::vector<int> &res) {
    if (!root) return;
    res.push_back(root->data);
    getPreorder(root->left, res);
    getPreorder(root->right, res);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);

    Solution sol;
    root = sol.buildBalancedTree(root);

    std::vector<int> pre;
    getPreorder(root, pre);
    std::vector<int> expected = {2, 1, 3, 4};
    assert(pre == expected);

    freeTree(root);

    std::cout << "7_bst 9_Convert_normal_BST_into_Balanced_BST: All tests passed.\n";
    return 0;
}
