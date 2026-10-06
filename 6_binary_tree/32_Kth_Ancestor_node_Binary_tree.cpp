#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool findPath(Node* root, int target, vector<int> &path) {
    if (!root) return false;
    path.push_back(root->data);
    if (root->data == target) return true;
    if (findPath(root->left, target, path) || findPath(root->right, target, path)) return true;
    path.pop_back();
    return false;
}

int kthAncestor(Node *root, int k, int node) {
    vector<int> path;
    if (!findPath(root, node, path)) return -1;
    int idx = path.size() - 1 - k;
    return (idx >= 0) ? path[idx] : -1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "2nd ancestor of 4: " << kthAncestor(root, 2, 4) << endl; // 1
    return 0;
}
