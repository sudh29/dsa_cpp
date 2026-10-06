#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void leftViewUtil(Node* root, int level, int &max_level, vector<int> &res) {
    if (!root) return;
    if (max_level < level) {
        res.push_back(root->data);
        max_level = level;
    }
    leftViewUtil(root->left, level + 1, max_level, res);
    leftViewUtil(root->right, level + 1, max_level, res);
}

vector<int> leftView(Node *root) {
    vector<int> res;
    int max_level = 0;
    leftViewUtil(root, 1, max_level, res);
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    auto res = leftView(root);
    cout << "Left view: ";
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
