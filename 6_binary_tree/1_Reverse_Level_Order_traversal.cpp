#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
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

std::vector<int> reverseLevelOrder(const Node *root) {
    std::vector<int> res;
    if (!root) return res;
    std::queue<const Node*> q;
    std::stack<int> s;
    q.push(root);

    while (!q.empty()) {
        const Node* cur = q.front();
        q.pop();
        s.push(cur->data);
        if (cur->right) q.push(cur->right);
        if (cur->left) q.push(cur->left);
    }
    res.reserve(s.size());
    while (!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    auto res = reverseLevelOrder(root);
    std::vector<int> expected = {4, 5, 2, 3, 1};
    assert(res == expected);

    assert(reverseLevelOrder(nullptr).empty());

    freeTree(root);

    std::cout << "6_binary_tree 1_Reverse_Level_Order_traversal: All tests passed.\n";
    return 0;
}
