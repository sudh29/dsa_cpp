#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void calculateLevelSums(Node* root, size_t level, vector<int> &sums) {
    if (!root) return;
    if (level == sums.size()) sums.push_back(0);
    sums[level] += root->data;
    calculateLevelSums(root->left, level + 1, sums);
    calculateLevelSums(root->right, level + 1, sums);
}

int maxLevelSumRec(Node* root) {
    vector<int> sums;
    calculateLevelSums(root, 0, sums);
    int maxSum = INT_MIN;
    for (int s : sums) maxSum = max(maxSum, s);
    return maxSum;
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(-5);
    root->left->left = new Node(-1);
    root->left->right = new Node(3);

    cout << "Max level sum (recursive): " << maxLevelSumRec(root) << endl;
    return 0;
}
