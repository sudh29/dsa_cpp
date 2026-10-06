#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;
    Node(int val) : data(val), next(nullptr), bottom(nullptr) {}
};

Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    Node* result;
    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = nullptr;
    return result;
}

Node* flatten(Node* root) {
    if (!root || !root->next) return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}

int main() {
    Node* root = new Node(5);
    root->bottom = new Node(7);
    root->bottom->bottom = new Node(8);

    root->next = new Node(10);
    root->next->bottom = new Node(20);

    root = flatten(root);
    cout << "Flattened list: ";
    Node* cur = root;
    while (cur) { cout << cur->data << " "; cur = cur->bottom; }
    cout << endl;
    return 0;
}
