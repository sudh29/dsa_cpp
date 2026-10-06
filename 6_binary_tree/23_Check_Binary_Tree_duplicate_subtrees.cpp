#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

struct Node {
    int data;
    Node* left;
    Node* right;
    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

class Solution {
private:
    std::unordered_map<std::string, int> subtrees;

    std::string serialize(const Node* root) {
        if (!root) return "$";
        std::string s = std::to_string(root->data) + "," + serialize(root->left) + "," + serialize(root->right);
        if (root->left || root->right) {
            subtrees[s]++;
        }
        return s;
    }

public:
    int dupSub(const Node *root) {
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
    // Subtree 2 with children 4 and 5 is duplicated
    assert(sol.dupSub(root) == 1);

    freeTree(root);

    std::cout << "6_binary_tree 23_Check_Binary_Tree_duplicate_subtrees: All tests passed.\n";
    return 0;
}
