#include <cassert>
#include <iostream>
#include <queue>
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

std::vector<int> diagonal(const Node *root) {
    std::vector<int> res;
    if (!root) return res;
    std::queue<const Node*> q;
    q.push(root);

    while (!q.empty()) {
        const Node* cur = q.front();
        q.pop();
        while (cur) {
            res.push_back(cur->data);
            if (cur->left) q.push(cur->left);
            cur = cur->right;
        }
    }
    return res;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);

    auto res = diagonal(root);
    // Diagonal 0: 8, 10
    // Diagonal 1: 3, 6
    // Diagonal 2: 1
    std::vector<int> expected = {8, 10, 3, 6, 1};
    assert(res == expected);

    assert(diagonal(nullptr).empty());

    freeTree(root);

    std::cout << "6_binary_tree 14_Diagonal_Traversal_tree: All tests passed.\n";
    return 0;
}
