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
    int heightAndDiameter(const Node* root, int &dia) const {
        if (!root) return 0;
        int lh = heightAndDiameter(root->left, dia);
        int rh = heightAndDiameter(root->right, dia);
        dia = std::max(dia, 1 + lh + rh);
        return 1 + std::max(lh, rh);
    }

public:
    int diameter(const Node* root) const {
        int dia = 0;
        heightAndDiameter(root, dia);
        return dia;
    }
};

int main() {
    Solution sol;
    assert(sol.diameter(nullptr) == 0);

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Diameter nodes: 4 -> 2 -> 1 -> 3 (or 5 -> 2 -> 1 -> 3), length in nodes = 4
    assert(sol.diameter(root) == 4);

    freeTree(root);

    std::cout << "6_binary_tree 3_Diameter_of_a_tree: All tests passed.\n";
    return 0;
}
