#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(Node* root, vector<int> &nodes) {
    if (!root) return;
    inorder(root->left, nodes);
    nodes.push_back(root->data);
    inorder(root->right, nodes);
}

void BSTToMinHeap(Node* root, const vector<int> &nodes, int &idx) {
    if (!root) return;
    root->data = nodes[idx++];
    BSTToMinHeap(root->left, nodes, idx);
    BSTToMinHeap(root->right, nodes, idx);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    vector<int> nodes;
    inorder(root, nodes);
    int idx = 0;
    BSTToMinHeap(root, nodes, idx);

    cout << "BST converted to Min Heap (Preorder): ";
    preorder(root);
    cout << endl;
    return 0;
}
