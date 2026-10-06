#include <iostream>
#include <vector>
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
    vector<Node*> duplicates;

    string serialize(Node* root) {
        if (!root) return "#";
        string s = to_string(root->data) + "," + serialize(root->left) + "," + serialize(root->right);
        subtrees[s]++;
        if (subtrees[s] == 2) duplicates.push_back(root);
        return s;
    }

    vector<Node*> printAllDups(Node* root) {
        subtrees.clear();
        duplicates.clear();
        serialize(root);
        return duplicates;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(2);
    root->right->left->left = new Node(4);
    root->right->right = new Node(4);

    Solution sol;
    auto dups = sol.printAllDups(root);
    cout << "Duplicate subtrees count: " << dups.size() << endl;
    return 0;
}
