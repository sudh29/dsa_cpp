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
    void printKPathUtil(const Node *root, std::vector<int>& path, int k, int &count) const {
        if (!root) return;
        path.push_back(root->data);
        printKPathUtil(root->left, path, k, count);
        printKPathUtil(root->right, path, k, count);

        int sum = 0;
        for (size_t j = path.size(); j > 0; --j) {
            sum += path[j - 1];
            if (sum == k) {
                count++;
            }
        }
        path.pop_back();
    }

public:
    int sumK(const Node *root, int k) const {
        std::vector<int> path;
        int count = 0;
        printKPathUtil(root, path, k, count);
        return count;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);

    Solution sol;
    // Paths with sum 5:
    // 3 -> 2 (sum 5)
    // 3 -> 1 -> 1 (sum 5)
    // 1 -> 3 -> 1 (sum 5)
    // Total count = 3
    assert(sol.sumK(root, 5) == 3);
    assert(sol.sumK(nullptr, 5) == 0);

    freeTree(root);

    std::cout << "6_binary_tree 29_Print_all_K_Sum_paths_Binary_tree: All tests passed.\n";
    return 0;
}
