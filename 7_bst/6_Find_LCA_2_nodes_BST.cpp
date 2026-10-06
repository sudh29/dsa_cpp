#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* LCA(Node* root, int n1, int n2) {
    if (!root) return nullptr;
    if (root->data > n1 && root->data > n2) return LCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2) return LCA(root->right, n1, n2);
    return root;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);

    Node* lca = LCA(root, 4, 12);
    cout << "LCA of 4 and 12: " << (lca ? lca->data : -1) << endl; // 8
    return 0;
}
