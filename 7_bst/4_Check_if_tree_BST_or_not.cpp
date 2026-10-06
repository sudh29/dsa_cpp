#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
        if (!root) return true;
        if (root->data <= minVal || root->data >= maxVal) return false;
        return isBSTUtil(root->left, minVal, root->data) &&
               isBSTUtil(root->right, root->data, maxVal);
    }

    bool isBST(Node* root) {
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    Solution sol;
    cout << "Is valid BST: " << (sol.isBST(root) ? "Yes" : "No") << endl;
    return 0;
}
