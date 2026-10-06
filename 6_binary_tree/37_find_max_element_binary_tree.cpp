#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findMax(Node* root) {
    if (!root) return INT_MIN;
    return max({root->data, findMax(root->left), findMax(root->right)});
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(7);
    root->right = new Node(5);
    root->left->right = new Node(6);
    root->left->right->left = new Node(11);

    cout << "Max element in binary tree: " << findMax(root) << endl; // 11
    return 0;
}
