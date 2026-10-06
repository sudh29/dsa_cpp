#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int minValue(Node* root) {
    if (!root) return -1;
    Node* cur = root;
    while (cur->left) cur = cur->left;
    return cur->data;
}

int maxValue(Node* root) {
    if (!root) return -1;
    Node* cur = root;
    while (cur->right) cur = cur->right;
    return cur->data;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->right->right = new Node(12);

    cout << "Min value: " << minValue(root) << " | Max value: " << maxValue(root) << endl;
    return 0;
}
