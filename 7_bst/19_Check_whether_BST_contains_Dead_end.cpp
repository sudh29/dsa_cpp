#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void storeNodes(Node* root, unordered_set<int> &all_nodes, unordered_set<int> &leaf_nodes) {
        if (!root) return;
        all_nodes.insert(root->data);
        if (!root->left && !root->right) leaf_nodes.insert(root->data);
        storeNodes(root->left, all_nodes, leaf_nodes);
        storeNodes(root->right, all_nodes, leaf_nodes);
    }

    bool isDeadEnd(Node *root) {
        unordered_set<int> all_nodes, leaf_nodes;
        all_nodes.insert(0);
        storeNodes(root, all_nodes, leaf_nodes);

        for (int val : leaf_nodes) {
            if (all_nodes.find(val - 1) != all_nodes.end() &&
                all_nodes.find(val + 1) != all_nodes.end()) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(9);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->left->left->left = new Node(1);

    Solution sol;
    cout << "Contains dead end: " << (sol.isDeadEnd(root) ? "Yes" : "No") << endl;
    return 0;
}
