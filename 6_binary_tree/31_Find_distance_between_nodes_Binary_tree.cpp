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
    Node* lca(Node* root, int a, int b) {
        if (!root || root->data == a || root->data == b) return root;
        Node* left = lca(root->left, a, b);
        Node* right = lca(root->right, a, b);
        if (left && right) return root;
        return left ? left : right;
    }

    int distFromLCA(Node* root, int val, int d) {
        if (!root) return -1;
        if (root->data == val) return d;
        int left = distFromLCA(root->left, val, d + 1);
        if (left != -1) return left;
        return distFromLCA(root->right, val, d + 1);
    }

    int findDist(Node* root, int a, int b) {
        Node* lcaNode = lca(root, a, b);
        return distFromLCA(lcaNode, a, 0) + distFromLCA(lcaNode, b, 0);
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    cout << "Distance between 4 and 5: " << sol.findDist(root, 4, 5) << endl; // 2
    return 0;
}
