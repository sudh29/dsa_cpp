#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void bToDLLUtil(Node* root, Node*& head, Node*& prev) {
        if (!root) return;
        bToDLLUtil(root->left, head, prev);
        if (!prev) {
            head = root;
        } else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        bToDLLUtil(root->right, head, prev);
    }

    Node *bToDLL(Node *root) {
        Node *head = nullptr, *prev = nullptr;
        bToDLLUtil(root, head, prev);
        return head;
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);

    Solution sol;
    Node* dll = sol.bToDLL(root);
    cout << "Binary tree to DLL: ";
    while (dll) { cout << dll->data << " "; dll = dll->right; }
    cout << endl;
    return 0;
}
