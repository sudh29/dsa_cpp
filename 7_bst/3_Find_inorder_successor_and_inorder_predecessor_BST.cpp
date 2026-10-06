#include <cassert>
#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
    explicit Node(int x) : key(x), left(nullptr), right(nullptr) {}
};

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

class Solution {
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        if (!root) return;

        if (root->key == key) {
            if (root->left) {
                Node* tmp = root->left;
                while (tmp->right) tmp = tmp->right;
                pre = tmp;
            }
            if (root->right) {
                Node* tmp = root->right;
                while (tmp->left) tmp = tmp->left;
                suc = tmp;
            }
            return;
        }

        if (root->key > key) {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        } else {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
    }
};

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);

    Node *pre = nullptr;
    Node *suc = nullptr;
    Solution sol;
    sol.findPreSuc(root, pre, suc, 30);
    assert(pre != nullptr && pre->key == 20);
    assert(suc != nullptr && suc->key == 40);

    pre = nullptr;
    suc = nullptr;
    sol.findPreSuc(root, pre, suc, 50);
    assert(pre != nullptr && pre->key == 40);
    assert(suc != nullptr && suc->key == 70);

    freeTree(root);

    std::cout << "7_bst 3_Find_inorder_successor_and_inorder_predecessor_BST: All tests passed.\n";
    return 0;
}
