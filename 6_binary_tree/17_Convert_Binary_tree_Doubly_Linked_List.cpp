#include <cassert>
#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* left;
    Node* right;
    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
private:
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

public:
    Node* bToDLL(Node *root) {
        Node* head = nullptr;
        Node* prev = nullptr;
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

    std::vector<int> vals;
    Node* cur = dll;
    while (cur) {
        vals.push_back(cur->data);
        cur = cur->right;
    }
    // Inorder: 25, 12, 30, 10, 15
    std::vector<int> expected = {25, 12, 30, 10, 15};
    assert(vals == expected);

    // Free all nodes in the DLL
    while (dll) {
        Node* tmp = dll;
        dll = dll->right;
        delete tmp;
    }

    std::cout << "6_binary_tree 17_Convert_Binary_tree_Doubly_Linked_List: All tests passed.\n";
    return 0;
}
