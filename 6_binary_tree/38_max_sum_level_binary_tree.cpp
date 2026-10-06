#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int maxLevelSum(Node* root) {
    if (!root) return 0;
    queue<Node*> q;
    q.push(root);
    int maxSum = INT_MIN;

    while (!q.empty()) {
        int sz = q.size();
        int levelSum = 0;
        for (int i = 0; i < sz; i++) {
            Node* cur = q.front();
            q.pop();
            levelSum += cur->data;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        maxSum = max(maxSum, levelSum);
    }
    return maxSum;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);

    cout << "Max level sum: " << maxLevelSum(root) << endl; // level 2 sum = 4+5+8 = 17
    return 0;
}
