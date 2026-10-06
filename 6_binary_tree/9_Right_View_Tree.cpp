#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void rightViewUtil(Node* root, int level, int &max_level, vector<int> &res) {
        if (!root) return;
        if (max_level < level) {
            res.push_back(root->data);
            max_level = level;
        }
        rightViewUtil(root->right, level + 1, max_level, res);
        rightViewUtil(root->left, level + 1, max_level, res);
    }

    vector<int> rightView(Node *root) {
        vector<int> res;
        int max_level = 0;
        rightViewUtil(root, 1, max_level, res);
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    Solution sol;
    auto res = sol.rightView(root);
    cout << "Right view: ";
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
