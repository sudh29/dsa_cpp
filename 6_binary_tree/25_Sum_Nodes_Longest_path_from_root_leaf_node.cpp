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
    void solve(Node* root, int len, int sum, int &maxLen, int &maxSum) {
        if (!root) return;
        sum += root->data;
        if (!root->left && !root->right) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            } else if (len == maxLen) {
                maxSum = max(maxSum, sum);
            }
            return;
        }
        solve(root->left, len + 1, sum, maxLen, maxSum);
        solve(root->right, len + 1, sum, maxLen, maxSum);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        int maxLen = 0, maxSum = 0;
        solve(root, 1, 0, maxLen, maxSum);
        return maxSum;
    }
};

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->right->left = new Node(2);
    root->right->right = new Node(3);
    root->left->right->left = new Node(6);

    Solution sol;
    cout << "Sum of nodes on longest root-to-leaf path: " << sol.sumOfLongRootToLeafPath(root) << endl;
    return 0;
}
