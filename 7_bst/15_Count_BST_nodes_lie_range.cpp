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
    int getCount(Node *root, int l, int h) {
        if (!root) return 0;
        if (root->data >= l && root->data <= h) {
            return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
        } else if (root->data < l) {
            return getCount(root->right, l, h);
        } else {
            return getCount(root->left, l, h);
        }
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    Solution sol;
    cout << "Count in range [5, 45]: " << sol.getCount(root, 5, 45) << endl;
    return 0;
}
