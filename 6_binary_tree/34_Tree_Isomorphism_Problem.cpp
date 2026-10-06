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
    bool isIsomorphic(const Node *root1, const Node *root2) const {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->data != root2->data) return false;

        bool same = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
        bool swapped = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);
        return same || swapped;
    }
};

int main() {
    Node* r1 = new Node(1); r1->left = new Node(2); r1->right = new Node(3);
    Node* r2 = new Node(1); r2->left = new Node(3); r2->right = new Node(2);

    Solution sol;
    assert(sol.isIsomorphic(r1, r2));

    Node* r3 = new Node(1); r3->left = new Node(4); r3->right = new Node(5);
    assert(!sol.isIsomorphic(r1, r3));

    freeTree(r1);
    freeTree(r2);
    freeTree(r3);

    std::cout << "6_binary_tree 34_Tree_Isomorphism_Problem: All tests passed.\n";
    return 0;
}
