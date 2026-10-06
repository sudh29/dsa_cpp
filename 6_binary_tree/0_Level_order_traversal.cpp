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

class Solution {
public:
    std::vector<int> levelOrder(const Node* root) {
        std::vector<int> res;
        if (!root) return res;
        std::queue<const Node*> q;
        q.push(root);

        while (!q.empty()) {
            const Node* cur = q.front();
            q.pop();
            res.push_back(cur->data);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    auto res = sol.levelOrder(root);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    assert(res == expected);

    assert(sol.levelOrder(nullptr).empty());

    freeTree(root);

    std::cout << "6_binary_tree 0_Level_order_traversal: All tests passed.\n";
    return 0;
}
