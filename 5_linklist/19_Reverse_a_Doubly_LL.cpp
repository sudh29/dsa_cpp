#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Reverse a Doubly Linked List
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Reverses a doubly linked list by swapping prev and next pointers for each node.
 */

struct Node {
    int data;
    Node* next{nullptr};
    Node* prev{nullptr};
    explicit Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

Node* reverseDLL(Node* head) {
    if (!head || !head->next) return head;
    Node* cur = head;
    Node* temp = nullptr;

    while (cur != nullptr) {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }

    if (temp != nullptr) {
        head = temp->prev;
    }
    return head;
}

Node* createDLL(std::span<const int> values) {
    if (values.empty()) return nullptr;
    Node* head = new Node(values[0]);
    Node* cur = head;
    for (size_t i = 1; i < values.size(); ++i) {
        Node* node = new Node(values[i]);
        cur->next = node;
        node->prev = cur;
        cur = node;
    }
    return head;
}

void freeDLL(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

std::vector<int> toVector(const Node* head) {
    std::vector<int> res;
    while (head != nullptr) {
        res.push_back(head->data);
        head = head->next;
    }
    return res;
}

int main() {
    // Test Case 1: [1, 2, 3] -> [3, 2, 1]
    {
        Node* head = createDLL(std::vector<int>{1, 2, 3});
        head = reverseDLL(head);
        assert(toVector(head) == (std::vector<int>{3, 2, 1}));
        freeDLL(head);
    }

    // Test Case 2: Single node [42] -> [42]
    {
        Node* head = createDLL(std::vector<int>{42});
        head = reverseDLL(head);
        assert(toVector(head) == (std::vector<int>{42}));
        freeDLL(head);
    }

    // Test Case 3: Empty list
    assert(reverseDLL(nullptr) == nullptr);

    std::cout << "[PASS] 5_linklist/19_Reverse_a_Doubly_LL: all tests passed!\n";
    return 0;
}
