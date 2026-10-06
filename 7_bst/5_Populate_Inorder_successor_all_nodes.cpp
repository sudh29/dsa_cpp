#include <cassert>
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* next;
    explicit Node(int val) : data(val), left(nullptr), right(nullptr), next(nullptr) {}
};

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

class Solution {
private:
    void populateNextUtil(Node* root, Node*& nextPtr) {
        if (!root) return;
        populateNextUtil(root->right, nextPtr);
        root->next = nextPtr;
        nextPtr = root;
        populateNextUtil(root->left, nextPtr);
    }

public:
    void populateNext(Node* root) {
        Node* nextPtr = nullptr;
        populateNextUtil(root, nextPtr);
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);

    Solution sol;
    sol.populateNext(root);

    // Inorder: 3, 8, 10, 12
    assert(root->left->left->next == root->left); // 3 -> 8
    assert(root->left->next == root);             // 8 -> 10
    assert(root->next == root->right);             // 10 -> 12
    assert(root->right->next == nullptr);          // 12 -> null

    freeTree(root);

    std::cout << "7_bst 5_Populate_Inorder_successor_all_nodes: All tests passed.\n";
    return 0;
}
