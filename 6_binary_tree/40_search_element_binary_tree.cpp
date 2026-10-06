#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool searchElement(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return searchElement(root->left, key) || searchElement(root->right, key);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    cout << "Search 20: " << (searchElement(root, 20) ? "Found" : "Not Found") << endl;
    cout << "Search 50: " << (searchElement(root, 50) ? "Found" : "Not Found") << endl;
    return 0;
}
