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
    int height(Node* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    Solution sol;
    cout << "Height of tree: " << sol.height(root) << endl;
    return 0;
}
