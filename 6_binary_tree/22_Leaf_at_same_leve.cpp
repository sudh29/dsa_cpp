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
    bool checkLevel(Node* root, int level, int &leafLevel) {
        if (!root) return true;
        if (!root->left && !root->right) {
            if (leafLevel == 0) {
                leafLevel = level;
                return true;
            }
            return (level == leafLevel);
        }
        return checkLevel(root->left, level + 1, leafLevel) &&
               checkLevel(root->right, level + 1, leafLevel);
    }

    bool check(Node *root) {
        int leafLevel = 0;
        return checkLevel(root, 1, leafLevel);
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    Solution sol;
    cout << "Leaves at same level: " << (sol.check(root) ? "Yes" : "No") << endl;
    return 0;
}
