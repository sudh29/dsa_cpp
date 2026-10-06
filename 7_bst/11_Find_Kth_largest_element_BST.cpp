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
    void reverseInorder(Node* root, int &k, int &ans) {
        if (!root || k <= 0) return;
        reverseInorder(root->right, k, ans);
        k--;
        if (k == 0) {
            ans = root->data;
            return;
        }
        reverseInorder(root->left, k, ans);
    }

    int kthLargest(Node *root, int K) {
        int ans = -1;
        reverseInorder(root, K, ans);
        return ans;
    }
};

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(9);

    Solution sol;
    cout << "2nd largest element: " << sol.kthLargest(root, 2) << endl;
    return 0;
}
