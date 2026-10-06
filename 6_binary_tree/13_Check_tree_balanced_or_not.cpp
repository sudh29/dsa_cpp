#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int checkHeight(Node* root) {
        if (!root) return 0;
        int lh = checkHeight(root->left);
        if (lh == -1) return -1;
        int rh = checkHeight(root->right);
        if (rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;
        return 1 + max(lh, rh);
    }

    bool isBalanced(Node *root) {
        return checkHeight(root) != -1;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    Solution sol;
    cout << "Is balanced: " << (sol.isBalanced(root) ? "Yes" : "No") << endl;
    return 0;
}
