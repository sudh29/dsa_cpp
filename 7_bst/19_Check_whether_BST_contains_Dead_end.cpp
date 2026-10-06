#include <cassert>
#include <iostream>
#include <unordered_set>

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
    void storeNodes(const Node* root, std::unordered_set<int> &allNodes, std::unordered_set<int> &leafNodes) {
        if (!root) return;
        allNodes.insert(root->data);
        if (!root->left && !root->right) {
            leafNodes.insert(root->data);
        }
        storeNodes(root->left, allNodes, leafNodes);
        storeNodes(root->right, allNodes, leafNodes);
    }

public:
    bool isDeadEnd(const Node *root) {
        std::unordered_set<int> allNodes;
        std::unordered_set<int> leafNodes;
        allNodes.insert(0); // Lower bound for natural numbers
        storeNodes(root, allNodes, leafNodes);

        for (int val : leafNodes) {
            if (allNodes.contains(val - 1) && allNodes.contains(val + 1)) {
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
    // Node 1 has adjacent 0 and 2 in tree, so it is a dead end
    assert(sol.isDeadEnd(root));

    // Construct a tree without dead ends: 8 -> left: 5, right: 11
    Node* root2 = new Node(8);
    root2->left = new Node(5);
    root2->right = new Node(11);
    assert(!sol.isDeadEnd(root2));

    freeTree(root);
    freeTree(root2);

    std::cout << "7_bst 19_Check_whether_BST_contains_Dead_end: All tests passed.\n";
    return 0;
}
