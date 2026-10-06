#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

std::unordered_map<Node*, int> memo;

int LISS(Node* root) {
    if (!root) return 0;
    if (memo.find(root) != memo.end()) return memo[root];

    // Exclude current node
    int size_excl = LISS(root->left) + LISS(root->right);

    // Include current node
    int size_incl = 1;
    if (root->left) {
        size_incl += LISS(root->left->left) + LISS(root->left->right);
    }
    if (root->right) {
        size_incl += LISS(root->right->left) + LISS(root->right->right);
    }

    return memo[root] = std::max(size_incl, size_excl);
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    assert(LISS(root) == 5);
    freeTree(root);

    std::cout << "38_Largest_Independent_Set_Problem tests passed.\n";
    return 0;
}
