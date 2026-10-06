#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Nth Node from End of Linked List
 * Module: 5_linklist
 * Time Complexity: O(L) where L is list length
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Finds the data of the n-th node from the end of a singly linked list using two pointers
 * separated by n positions. Returns -1 if n > length.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

int getNthFromLast(Node* head, int n) {
    if (!head || n <= 0) return -1;
    Node* first = head;
    Node* second = head;

    for (int i = 0; i < n; ++i) {
        if (!first) return -1;
        first = first->next;
    }

    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }
    return second ? second->data : -1;
}

Node* createList(std::span<const int> values) {
    if (values.empty()) return nullptr;
    Node* head = new Node(values[0]);
    Node* cur = head;
    for (size_t i = 1; i < values.size(); ++i) {
        cur->next = new Node(values[i]);
        cur = cur->next;
    }
    return head;
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test Case 1: [1, 2, 3, 4, 5] -> 2nd from last is 4
    {
        Node* head = createList(std::vector<int>{1, 2, 3, 4, 5});
        assert(getNthFromLast(head, 2) == 4);
        assert(getNthFromLast(head, 1) == 5);
        assert(getNthFromLast(head, 5) == 1);
        assert(getNthFromLast(head, 6) == -1);
        freeList(head);
    }

    // Test Case 2: Single node [10]
    {
        Node* head = createList(std::vector<int>{10});
        assert(getNthFromLast(head, 1) == 10);
        assert(getNthFromLast(head, 2) == -1);
        freeList(head);
    }

    // Test Case 3: Nullptr
    assert(getNthFromLast(nullptr, 1) == -1);

    std::cout << "[PASS] 5_linklist/34_Nth_node_from_end_of_LL: all tests passed!\n";
    return 0;
}
