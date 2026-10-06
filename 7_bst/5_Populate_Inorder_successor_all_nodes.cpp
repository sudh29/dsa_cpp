#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* next;
    Node(int val) : data(val), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    void populateNextUtil(Node* root, Node*& nextPtr) {
        if (!root) return;
        populateNextUtil(root->right, nextPtr);
        root->next = nextPtr;
        nextPtr = root;
        populateNextUtil(root->left, nextPtr);
    }

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
    cout << "Inorder successor of 8: " << (root->left->next ? root->left->next->data : -1) << endl; // 10
    return 0;
}
