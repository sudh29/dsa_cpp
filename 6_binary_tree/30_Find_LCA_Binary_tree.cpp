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
    Node* lca(Node* root, int n1, int n2) {
        if (!root) return nullptr;
        if (root->data == n1 || root->data == n2) return root;

        Node* left = lca(root->left, n1, n2);
        Node* right = lca(root->right, n1, n2);

        if (left && right) return root;
        return left ? left : right;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    Node* ans = sol.lca(root, 4, 5);
    cout << "LCA of 4 and 5 in Binary Tree: " << (ans ? ans->data : -1) << endl; // 2
    return 0;
}
