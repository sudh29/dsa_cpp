#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

struct AVLNode {
    int key;
    int height;
    AVLNode *left;
    AVLNode *right;
    explicit AVLNode(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

void freeTree(AVLNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int height(const AVLNode *N) { return N ? N->height : 0; }
int getBalance(const AVLNode *N) { return N ? height(N->left) - height(N->right) : 0; }

AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLNode *leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    return y;
}

AVLNode* insertAVL(AVLNode* node, int key) {
    if (!node) return new AVLNode(key);
    if (key < node->key) node->left = insertAVL(node->left, key);
    else if (key > node->key) node->right = insertAVL(node->right, key);
    else return node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && key < node->left->key) return rightRotate(node);
    // Right Right
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    // Left Right
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void getInorder(const AVLNode *root, std::vector<int> &res) {
    if (!root) return;
    getInorder(root->left, res);
    res.push_back(root->key);
    getInorder(root->right, res);
}

bool isAVLBalanced(const AVLNode *root) {
    if (!root) return true;
    int bal = getBalance(root);
    if (bal < -1 || bal > 1) return false;
    return isAVLBalanced(root->left) && isAVLBalanced(root->right);
}

int main() {
    AVLNode *root = nullptr;
    for (int k : {10, 20, 30, 40, 50, 25}) {
        root = insertAVL(root, k);
    }

    assert(isAVLBalanced(root));

    std::vector<int> in;
    getInorder(root, in);
    std::vector<int> expected = {10, 20, 25, 30, 40, 50};
    assert(in == expected);

    freeTree(root);

    std::cout << "7_bst 22_AVL_Tree_Operations: All tests passed.\n";
    return 0;
}
