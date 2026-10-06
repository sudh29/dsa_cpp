#include <iostream>
#include <algorithm>

using namespace std;

struct AVLNode {
    int key, height;
    AVLNode *left, *right;
    AVLNode(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

int height(AVLNode *N) { return N ? N->height : 0; }
int getBalance(AVLNode *N) { return N ? height(N->left) - height(N->right) : 0; }

AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLNode *leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

AVLNode* insertAVL(AVLNode* node, int key) {
    if (!node) return new AVLNode(key);
    if (key < node->key) node->left = insertAVL(node->left, key);
    else if (key > node->key) node->right = insertAVL(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
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

void preOrder(AVLNode *root) {
    if (!root) return;
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    AVLNode *root = nullptr;
    for (int k : {10, 20, 30, 40, 50, 25}) root = insertAVL(root, k);
    cout << "Preorder of balanced AVL tree: ";
    preOrder(root);
    cout << endl;
    return 0;
}
