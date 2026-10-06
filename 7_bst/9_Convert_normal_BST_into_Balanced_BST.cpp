#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void inorder(Node* root, vector<Node*> &nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

    Node* buildBalanced(const vector<Node*> &nodes, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        Node* root = nodes[mid];
        root->left = buildBalanced(nodes, start, mid - 1);
        root->right = buildBalanced(nodes, mid + 1, end);
        return root;
    }

    Node* buildBalancedTree(Node* root) {
        vector<Node*> nodes;
        inorder(root, nodes);
        return buildBalanced(nodes, 0, nodes.size() - 1);
    }
};

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);

    Solution sol;
    root = sol.buildBalancedTree(root);
    cout << "Preorder of balanced BST: ";
    preorder(root);
    cout << endl;
    return 0;
}
