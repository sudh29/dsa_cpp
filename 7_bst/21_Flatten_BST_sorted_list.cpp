#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorderFlatten(Node* cur, Node*& prev) {
    if (!cur) return;
    inorderFlatten(cur->left, prev);
    prev->left = nullptr;
    prev->right = cur;
    prev = cur;
    inorderFlatten(cur->right, prev);
}

Node* flatten(Node* root) {
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    inorderFlatten(root, prev);
    prev->left = nullptr;
    prev->right = nullptr;
    Node* ret = dummy->right;
    delete dummy;
    return ret;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);

    Node* flat = flatten(root);
    cout << "Flattened sorted list: ";
    while (flat) { cout << flat->data << " "; flat = flat->right; }
    cout << endl;
    return 0;
}
