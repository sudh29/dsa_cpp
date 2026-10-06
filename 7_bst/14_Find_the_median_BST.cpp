#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(Node* root, vector<int> &v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

float findMedian(Node *root) {
    vector<int> v;
    inorder(root, v);
    int n = v.size();
    if (n == 0) return 0;
    if (n % 2 != 0) return v[n / 2];
    return (v[(n / 2) - 1] + v[n / 2]) / 2.0f;
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    cout << "Median of BST: " << findMedian(root) << endl;
    return 0;
}
