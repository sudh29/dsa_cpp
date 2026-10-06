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
    int checkSumTree(Node* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->data;

        int ls = checkSumTree(root->left);
        if (ls == -1) return -1;
        int rs = checkSumTree(root->right);
        if (rs == -1) return -1;

        if (root->data == ls + rs) return 2 * root->data;
        return -1;
    }

    bool isSumTree(Node* root) {
        return checkSumTree(root) != -1;
    }
};

int main() {
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    Solution sol;
    cout << "Is sum tree: " << (sol.isSumTree(root) ? "Yes" : "No") << endl;
    return 0;
}
