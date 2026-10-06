#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int toSumTreeUtil(Node* root) {
        if (!root) return 0;
        int oldVal = root->data;
        root->data = toSumTreeUtil(root->left) + toSumTreeUtil(root->right);
        return root->data + oldVal;
    }

    void toSumTree(Node *node) {
        toSumTreeUtil(node);
    }
};

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    Solution sol;
    sol.toSumTree(root);
    cout << "Inorder of converted Sum Tree: ";
    inorder(root);
    cout << endl;
    return 0;
}
