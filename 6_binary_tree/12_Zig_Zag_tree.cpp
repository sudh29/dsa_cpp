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
    std::vector<int> zigZagTraversal(const Node* root) const {
        std::vector<int> res;
        if (!root) return res;
        std::queue<const Node*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            size_t sz = q.size();
            std::vector<int> level(sz);
            for (size_t i = 0; i < sz; ++i) {
                const Node* cur = q.front();
                q.pop();
                size_t idx = leftToRight ? i : (sz - 1 - i);
                level[idx] = cur->data;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            leftToRight = !leftToRight;
            for (int v : level) res.push_back(v);
        }
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    Solution sol;
    auto res = sol.zigZagTraversal(root);
    // Level 1: [1], Level 2 (R to L): [3, 2], Level 3 (L to R): [4, 5]
    std::vector<int> expected = {1, 3, 2, 4, 5};
    assert(res == expected);

    assert(sol.zigZagTraversal(nullptr).empty());

    freeTree(root);

    std::cout << "6_binary_tree 12_Zig_Zag_tree: All tests passed.\n";
    return 0;
}
