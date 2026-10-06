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

std::vector<int> bottomView(const Node *root) {
    std::vector<int> res;
    if (!root) return res;
    std::map<int, int> botNode;
    std::queue<std::pair<const Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [cur, hd] = q.front();
        q.pop();
        botNode[hd] = cur->data;
        if (cur->left) q.push({cur->left, hd - 1});
        if (cur->right) q.push({cur->right, hd + 1});
    }

    res.reserve(botNode.size());
    for (const auto &[hd, val] : botNode) {
        res.push_back(val);
    }
    return res;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(25);

    auto res = bottomView(root);
    // hd -2: 5, hd -1: 8 (or overwritten if child exists? wait: 3 has hd 0! root has hd 0. So 3 overwrites 20), hd 1: 22, hd 2: 25
    // hd -2: 5, hd -1: 8, hd 0: 3, hd 1: 22, hd 2: 25
    std::vector<int> expected = {5, 8, 3, 22, 25};
    assert(res == expected);

    assert(bottomView(nullptr).empty());

    freeTree(root);

    std::cout << "6_binary_tree 11_Bottom_View_tree: All tests passed.\n";
    return 0;
}
