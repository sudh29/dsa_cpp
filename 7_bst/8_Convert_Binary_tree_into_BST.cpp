#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void inorderExtract(Node* root, vector<int> &nodes) {
        if (!root) return;
        inorderExtract(root->left, nodes);
        nodes.push_back(root->data);
        inorderExtract(root->right, nodes);
    }

    void inorderFill(Node* root, const vector<int> &nodes, int &idx) {
        if (!root) return;
        inorderFill(root->left, nodes, idx);
        root->data = nodes[idx++];
        inorderFill(root->right, nodes, idx);
    }

    Node *binaryTreeToBST(Node *root) {
        vector<int> nodes;
        inorderExtract(root, nodes);
        sort(nodes.begin(), nodes.end());
        int idx = 0;
        inorderFill(root, nodes, idx);
        return root;
    }
};

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Solution sol;
    sol.binaryTreeToBST(root);
    cout << "Inorder of converted BST: ";
    inorderPrint(root);
    cout << endl;
    return 0;
}
