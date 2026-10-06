#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
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
    std::vector<int> topView(const Node *root) const {
        std::vector<int> res;
        if (!root) return res;
        std::map<int, int> topNode; // hd -> val
        std::queue<std::pair<const Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto [cur, hd] = q.front();
            q.pop();
            if (!topNode.contains(hd)) {
                topNode[hd] = cur->data;
            }
            if (cur->left) q.push({cur->left, hd - 1});
            if (cur->right) q.push({cur->right, hd + 1});
        }

        res.reserve(topNode.size());
        for (const auto &[hd, val] : topNode) {
            res.push_back(val);
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
    auto res = sol.topView(root);
    // Leftmost hd -2: 4, hd -1: 2, hd 0: 1, hd 1: 3
    std::vector<int> expected = {4, 2, 1, 3};
    assert(res == expected);

    assert(sol.topView(nullptr).empty());

    freeTree(root);

    std::cout << "6_binary_tree 10_Top_View_tree: All tests passed.\n";
    return 0;
}
