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
    void inorderHelper(Node* root, vector<int> &res) {
        if (!root) return;
        inorderHelper(root->left, res);
        res.push_back(root->data);
        inorderHelper(root->right, res);
    }

    vector<int> inorderTraversal(Node* root) {
        vector<int> res;
        inorderHelper(root, res);
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->left = new Node(3);

    Solution sol;
    auto res = sol.inorderTraversal(root);
    cout << "Inorder: ";
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
