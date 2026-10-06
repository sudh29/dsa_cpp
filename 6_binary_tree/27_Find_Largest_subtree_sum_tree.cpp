#include <iostream>
#include <algorithm>
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
    int solve(Node* root, int &ans) {
        if (!root) return 0;
        int curSum = root->data + solve(root->left, ans) + solve(root->right, ans);
        ans = max(ans, curSum);
        return curSum;
    }

    int findLargestSubtreeSum(Node* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);

    Solution sol;
    cout << "Largest subtree sum: " << sol.findLargestSubtreeSum(root) << endl; // 7
    return 0;
}
