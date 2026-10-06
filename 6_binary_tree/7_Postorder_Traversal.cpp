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
    void postorderHelper(Node* root, vector<int> &res) {
        if (!root) return;
        postorderHelper(root->left, res);
        postorderHelper(root->right, res);
        res.push_back(root->data);
    }

    vector<int> postorderTraversal(Node* root) {
        vector<int> res;
        postorderHelper(root, res);
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->left = new Node(3);

    Solution sol;
    auto res = sol.postorderTraversal(root);
    cout << "Postorder: ";
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
