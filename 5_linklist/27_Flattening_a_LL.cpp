#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Flattening a Linked List (Multilevel with bottom pointers)
 * Module: 5_linklist
 * Time Complexity: O(N * M) where N is number of main heads, M is bottom nodes
 * Space Complexity: O(N) recursion stack
 *
 * Description:
 * Given a linked list where every node has a next and a bottom pointer, flattens the list
 * into a single sorted list linked via bottom pointers.
 */

struct Node {
    int data;
    Node* next{nullptr};
    Node* bottom{nullptr};
    explicit Node(int val) : data(val), next(nullptr), bottom(nullptr) {}
};

Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    Node* result = nullptr;
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

void freeFlattenedList(Node* root) {
    while (root != nullptr) {
        Node* temp = root;
        root = root->bottom;
        delete temp;
    }
}

std::vector<int> toBottomVector(const Node* root) {
    std::vector<int> res;
    while (root != nullptr) {
        res.push_back(root->data);
        root = root->bottom;
    }
    return res;
}

int main() {
    // Test Case 1: Standard multilevel list
    // List 1: 5 -> 7 -> 8
    // List 2: 10 -> 20
    {
        Node* root = new Node(5);
        root->bottom = new Node(7);
        root->bottom->bottom = new Node(8);

        root->next = new Node(10);
        root->next->bottom = new Node(20);

        root = flatten(root);
        std::vector<int> expected = {5, 7, 8, 10, 20};
        assert(toBottomVector(root) == expected);

        freeFlattenedList(root);
    }

    // Test Case 2: Single node
    {
        Node* root = new Node(42);
        root = flatten(root);
        assert(toBottomVector(root) == (std::vector<int>{42}));
        freeFlattenedList(root);
    }

    // Test Case 3: Nullptr
    assert(flatten(nullptr) == nullptr);

    std::cout << "[PASS] 5_linklist/27_Flattening_a_LL: all tests passed!\n";
    return 0;
}
