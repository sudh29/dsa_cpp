#include <cassert>
#include <iostream>
#include <vector>

struct BSTNode {
    int data;
    BSTNode *left;
    BSTNode *right;
    explicit BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void freeTree(BSTNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

class BSTOperations {
public:
    BSTNode* insert(BSTNode* root, int val) {
        if (!root) return new BSTNode(val);
        if (val < root->data) root->left = insert(root->left, val);
        else if (val > root->data) root->right = insert(root->right, val);
        return root;
    }

    bool search(const BSTNode* root, int val) const {
        if (!root) return false;
        if (root->data == val) return true;
        if (val < root->data) return search(root->left, val);
        return search(root->right, val);
    }

    BSTNode* findMin(BSTNode* root) {
        while (root && root->left) root = root->left;
        return root;
    }

    BSTNode* remove(BSTNode* root, int val) {
        if (!root) return nullptr;
        if (val < root->data) root->left = remove(root->left, val);
        else if (val > root->data) root->right = remove(root->right, val);
        else {
            if (!root->left) {
                BSTNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                BSTNode* temp = root->left;
                delete root;
                return temp;
            }
            BSTNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
        return root;
    }

    void inorder(const BSTNode* root, std::vector<int> &res) const {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);
    }
};

int main() {
    BSTOperations ops;
    BSTNode* root = nullptr;
    for (int v : {50, 30, 20, 40, 70, 60, 80}) {
        root = ops.insert(root, v);
    }

    std::vector<int> in;
    ops.inorder(root, in);
    std::vector<int> expected = {20, 30, 40, 50, 60, 70, 80};
    assert(in == expected);

    assert(ops.search(root, 40));
    assert(!ops.search(root, 99));

    root = ops.remove(root, 20);
    assert(!ops.search(root, 20));

    in.clear();
    ops.inorder(root, in);
    expected = {30, 40, 50, 60, 70, 80};
    assert(in == expected);

    freeTree(root);

    std::cout << "7_bst 23_BST_Insert_Delete_Search: All tests passed.\n";
    return 0;
}
