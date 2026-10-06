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
    void preorderHelper(Node* root, vector<int> &res) {
        if (!root) return;
        res.push_back(root->data);
        preorderHelper(root->left, res);
        preorderHelper(root->right, res);
    }

    vector<int> preorderTraversal(Node* root) {
        vector<int> res;
        preorderHelper(root, res);
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->left = new Node(3);

    Solution sol;
    auto res = sol.preorderTraversal(root);
    cout << "Preorder: ";
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
