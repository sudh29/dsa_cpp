#include <iostream>

using namespace std;

struct BSTNode {
    int data;
    BSTNode *left, *right;
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BSTOperations {
public:
    BSTNode* insert(BSTNode* root, int val) {
        if (!root) return new BSTNode(val);
        if (val < root->data) root->left = insert(root->left, val);
        else if (val > root->data) root->right = insert(root->right, val);
        return root;
    }

    bool search(BSTNode* root, int val) {
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

    void inorder(BSTNode* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    BSTOperations ops;
    BSTNode* root = nullptr;
    for (int v : {50, 30, 20, 40, 70, 60, 80}) root = ops.insert(root, v);

    cout << "Inorder: ";
    ops.inorder(root);
    cout << "\nSearch 40: " << (ops.search(root, 40) ? "Found" : "Not Found") << endl;

    root = ops.remove(root, 20);
    cout << "After removing 20: ";
    ops.inorder(root);
    cout << endl;
    return 0;
}
