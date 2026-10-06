#include <cassert>
#include <iostream>
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
    bool isLeaf(const Node* root) const {
        return (!root->left && !root->right);
    }

    void addLeftBoundary(const Node* root, std::vector<int> &res) const {
        const Node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) res.push_back(cur->data);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }

    void addLeaves(const Node* root, std::vector<int> &res) const {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }

    void addRightBoundary(const Node* root, std::vector<int> &res) const {
        const Node* cur = root->right;
        std::vector<int> temp;
        while (cur) {
            if (!isLeaf(cur)) temp.push_back(cur->data);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for (size_t i = temp.size(); i > 0; --i) {
            res.push_back(temp[i - 1]);
        }
    }

public:
    std::vector<int> boundary(const Node *root) const {
        std::vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
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
    auto res = sol.boundary(root);
    // Boundary: root(1), left boundary(2), leaves(4, 5), right boundary(3)
    std::vector<int> expected = {1, 2, 4, 5, 3};
    assert(res == expected);

    assert(sol.boundary(nullptr).empty());

    freeTree(root);

    std::cout << "6_binary_tree 15_Boundary_traversal_tree: All tests passed.\n";
    return 0;
}
