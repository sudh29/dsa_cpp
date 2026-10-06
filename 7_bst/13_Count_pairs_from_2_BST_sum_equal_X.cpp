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
    void insertSet(const Node* root, std::unordered_set<int> &s) {
        if (!root) return;
        insertSet(root->left, s);
        s.insert(root->data);
        insertSet(root->right, s);
    }

    void countPairsUtil(const Node* root, const std::unordered_set<int> &s, int x, int &count) {
        if (!root) return;
        countPairsUtil(root->left, s, x, count);
        if (s.find(x - root->data) != s.end()) count++;
        countPairsUtil(root->right, s, x, count);
    }

public:
    int countPairs(const Node* root1, const Node* root2, int x) {
        std::unordered_set<int> s;
        insertSet(root1, s);
        int count = 0;
        countPairsUtil(root2, s, x, count);
        return count;
    }
};

int main() {
    Node* r1 = new Node(5); r1->left = new Node(3); r1->right = new Node(7);
    Node* r2 = new Node(10); r2->left = new Node(6); r2->right = new Node(15);

    Solution sol;
    assert(sol.countPairs(r1, r2, 16) == 0); // No pairs sum to 16
    assert(sol.countPairs(r1, r2, 13) == 2); // (7 + 6) and (3 + 10)
    assert(sol.countPairs(r1, r2, 15) == 1); // (5 + 10)
    assert(sol.countPairs(r1, r2, 18) == 1); // (3 + 15)
    assert(sol.countPairs(r1, r2, 99) == 0);

    freeTree(r1);
    freeTree(r2);

    std::cout << "7_bst 13_Count_pairs_from_2_BST_sum_equal_X: All tests passed.\n";
    return 0;
}
