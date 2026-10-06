#include <cassert>
#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* left;
    Node* right;
    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorderFlatten(Node* cur, Node*& prev) {
    if (!cur) return;
    inorderFlatten(cur->left, prev);
    prev->left = nullptr;
    prev->right = cur;
    prev = cur;
    inorderFlatten(cur->right, prev);
}

Node* flatten(Node* root) {
    Node dummy(-1);
    Node* prev = &dummy;
    inorderFlatten(root, prev);
    prev->left = nullptr;
    prev->right = nullptr;
    return dummy.right;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);

    Node* flat = flatten(root);

    std::vector<int> vals;
    for (Node* curr = flat; curr != nullptr; curr = curr->right) {
        assert(curr->left == nullptr);
        vals.push_back(curr->data);
    }
    std::vector<int> expected = {2, 3, 5, 7};
    assert(vals == expected);

    // Free the singly-linked list of nodes
    while (flat) {
        Node* tmp = flat;
        flat = flat->right;
        delete tmp;
    }

    std::cout << "7_bst 21_Flatten_BST_sorted_list: All tests passed.\n";
    return 0;
}
