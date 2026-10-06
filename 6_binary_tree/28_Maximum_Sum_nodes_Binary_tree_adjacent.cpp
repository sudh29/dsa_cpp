#include <iostream>
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
    // returns {including_root, excluding_root}
    pair<int, int> dfs(Node* root) {
        if (!root) return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);

        int incl = root->data + l.second + r.second;
        int excl = max(l.first, l.second) + max(r.first, r.second);
        return {incl, excl};
    }

    int getMaxSum(Node *root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    Solution sol;
    cout << "Max sum without adjacent nodes: " << sol.getMaxSum(root) << endl;
    return 0;
}
