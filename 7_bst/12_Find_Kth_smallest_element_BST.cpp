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
    void inorder(Node* root, int &k, int &ans) {
        if (!root || k <= 0) return;
        inorder(root->left, k, ans);
        k--;
        if (k == 0) {
            ans = root->data;
            return;
        }
        inorder(root->right, k, ans);
    }

    int KthSmallestElement(Node *root, int K) {
        int ans = -1;
        inorder(root, K, ans);
        return ans;
    }
};

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(9);
    root->left->left = new Node(1);

    Solution sol;
    cout << "2nd smallest element: " << sol.KthSmallestElement(root, 2) << endl;
    return 0;
}
