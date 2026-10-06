#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Node* build(int in[], int pre[], int inStart, int inEnd, int &preIdx, unordered_map<int, int> &inMap) {
        if (inStart > inEnd) return nullptr;
        int rootVal = pre[preIdx++];
        Node* root = new Node(rootVal);
        int inIndex = inMap[rootVal];

        root->left = build(in, pre, inStart, inIndex - 1, preIdx, inMap);
        root->right = build(in, pre, inIndex + 1, inEnd, preIdx, inMap);
        return root;
    }

    Node* buildTree(int in[], int pre[], int n) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < n; i++) inMap[in[i]] = i;
        int preIdx = 0;
        return build(in, pre, 0, n - 1, preIdx, inMap);
    }
};

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    Solution sol;
    Node* root = sol.buildTree(in, pre, 6);
    cout << "Postorder of built tree: ";
    postorder(root);
    cout << endl;
    return 0;
}
