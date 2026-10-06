#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    bool search(Node* root, int x) {
        if (!root) return false;
        if (root->data == x) return true;
        if (x < root->data) return search(root->left, x);
        return search(root->right, x);
    }
};

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    BST bst;
    cout << "Search 3 in BST: " << (bst.search(root, 3) ? "Found" : "Not Found") << endl;
    cout << "Search 5 in BST: " << (bst.search(root, 5) ? "Found" : "Not Found") << endl;
    return 0;
}
