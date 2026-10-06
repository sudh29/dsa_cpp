#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

struct NodeInfo {
    int size;
    int maxVal;
    int minVal;
    int ans;
    bool isBST;
};

class Solution {
public:
    NodeInfo largestBSTUtil(Node* root) {
        if (!root) return {0, INT_MIN, INT_MAX, 0, true};
        if (!root->left && !root->right) return {1, root->data, root->data, 1, true};

        NodeInfo l = largestBSTUtil(root->left);
        NodeInfo r = largestBSTUtil(root->right);

        NodeInfo ret;
        ret.size = 1 + l.size + r.size;

        if (l.isBST && r.isBST && l.maxVal < root->data && r.minVal > root->data) {
            ret.minVal = min(root->data, l.minVal);
            ret.maxVal = max(root->data, r.maxVal);
            ret.ans = ret.size;
            ret.isBST = true;
            return ret;
        }

        ret.ans = max(l.ans, r.ans);
        ret.isBST = false;
        return ret;
    }

    int largestBst(Node *root) {
        return largestBSTUtil(root).ans;
    }
};

int main() {
    Node* root = new Node(6);
    root->left = new Node(6);
    root->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(9);

    Solution sol;
    cout << "Largest BST size in Binary Tree: " << sol.largestBst(root) << endl;
    return 0;
}
