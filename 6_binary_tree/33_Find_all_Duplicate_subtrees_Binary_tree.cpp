#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

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
    std::vector<Node*> duplicates;

    std::string serialize(Node* root) {
        if (!root) return "#";
        std::string s = std::to_string(root->data) + "," + serialize(root->left) + "," + serialize(root->right);
        subtrees[s]++;
        if (subtrees[s] == 2) {
            duplicates.push_back(root);
        }
        return s;
    }

public:
    std::vector<Node*> printAllDups(Node* root) {
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
    // Duplicate subtrees: subtree '4' and subtree '2 -> 4'
    assert(dups.size() == 2);

    freeTree(root);

    std::cout << "6_binary_tree 33_Find_all_Duplicate_subtrees_Binary_tree: All tests passed.\n";
    return 0;
}
