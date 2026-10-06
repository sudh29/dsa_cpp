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
    int countNodes(const Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isComplete(const Node* root, int index, int totalNodes) {
        if (!root) return true;
        if (index >= totalNodes) return false;
        return isComplete(root->left, 2 * index + 1, totalNodes) &&
               isComplete(root->right, 2 * index + 2, totalNodes);
    }

    bool isHeapProperty(const Node* root) {
        if (!root->left && !root->right) return true;
        if (!root->right) {
            return root->data >= root->left->data;
        }
        if (root->data >= root->left->data && root->data >= root->right->data) {
            return isHeapProperty(root->left) && isHeapProperty(root->right);
        }
        return false;
    }

public:
    bool isHeap(const Node* root) {
        if (!root) return true;
        int total = countNodes(root);
        return isComplete(root, 0, total) && isHeapProperty(root);
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);

    Solution sol;
    assert(sol.isHeap(root));

    // Violate heap property
    root->left->right->data = 15;
    assert(!sol.isHeap(root));

    freeTree(root);

    std::cout << "11_heap 12_Is_Binary_Tree_Heap: All tests passed.\n";
    return 0;
}
