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
    const Node* lca(const Node* root, int a, int b) const {
        if (!root || root->data == a || root->data == b) return root;
        const Node* left = lca(root->left, a, b);
        const Node* right = lca(root->right, a, b);
        if (left && right) return root;
        return left ? left : right;
    }

    int distFromLCA(const Node* root, int val, int d) const {
        if (!root) return -1;
        if (root->data == val) return d;
        int left = distFromLCA(root->left, val, d + 1);
        if (left != -1) return left;
        return distFromLCA(root->right, val, d + 1);
    }

public:
    int findDist(const Node* root, int a, int b) const {
        const Node* lcaNode = lca(root, a, b);
        if (!lcaNode) return -1;
        int d1 = distFromLCA(lcaNode, a, 0);
        int d2 = distFromLCA(lcaNode, b, 0);
        if (d1 == -1 || d2 == -1) return -1;
        return d1 + d2;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    assert(sol.findDist(root, 4, 5) == 2);
    assert(sol.findDist(root, 4, 3) == 3);
    assert(sol.findDist(root, 1, 4) == 2);

    freeTree(root);

    std::cout << "6_binary_tree 31_Find_distance_between_nodes_Binary_tree: All tests passed.\n";
    return 0;
}
