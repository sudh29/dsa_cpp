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
    void inorder(const Node* root, std::vector<int> &res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);
    }

public:
    std::vector<int> merge(const Node *root1, const Node *root2) {
        std::vector<int> a, b;
        inorder(root1, a);
        inorder(root2, b);

        std::vector<int> res;
        res.reserve(a.size() + b.size());
        size_t i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) res.push_back(a[i++]);
            else res.push_back(b[j++]);
        }
        while (i < a.size()) res.push_back(a[i++]);
        while (j < b.size()) res.push_back(b[j++]);
        return res;
    }
};

int main() {
    Node* r1 = new Node(3); r1->left = new Node(1); r1->right = new Node(5);
    Node* r2 = new Node(4); r2->left = new Node(2); r2->right = new Node(6);

    Solution sol;
    auto merged = sol.merge(r1, r2);
    std::vector<int> expected = {1, 2, 3, 4, 5, 6};
    assert(merged == expected);

    freeTree(r1);
    freeTree(r2);

    std::cout << "7_bst 10_Merge_two_BST: All tests passed.\n";
    return 0;
}
