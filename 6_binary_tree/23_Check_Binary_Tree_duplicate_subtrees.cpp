#include <iostream>
#include <string>
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
    unordered_map<string, int> subtrees;

    string serialize(Node* root) {
        if (!root) return "$";
        string s = to_string(root->data) + "," + serialize(root->left) + "," + serialize(root->right);
        if (root->left || root->right) subtrees[s]++;
        return s;
    }

    int dupSub(Node *root) {
        subtrees.clear();
        serialize(root);
        for (const auto &[str, count] : subtrees) {
            if (count >= 2) return 1;
        }
        return 0;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(2);
    root->right->right->left = new Node(4);
    root->right->right->right = new Node(5);

    Solution sol;
    cout << "Contains duplicate subtree (size >= 2): " << (sol.dupSub(root) ? "Yes" : "No") << endl;
    return 0;
}
