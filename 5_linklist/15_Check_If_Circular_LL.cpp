#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Check If Linked List is Circular
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Checks whether a given linked list is circular (its last node points back to the head).
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

bool isCircular(Node* head) {
    if (!head) return true;
    Node* cur = head->next;
    while (cur != nullptr && cur != head) {
        cur = cur->next;
    }
    return cur == head;
}

Node* createCircularList(std::span<const int> values) {
    if (values.empty()) return nullptr;
    Node* head = new Node(values[0]);
    Node* cur = head;
    for (size_t i = 1; i < values.size(); ++i) {
        cur->next = new Node(values[i]);
        cur = cur->next;
    }
    cur->next = head; // close circle
    return head;
}

void freeCircularList(Node* head) {
    if (!head) return;
    Node* cur = head->next;
    while (cur != nullptr && cur != head) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }
    delete head;
}

int main() {
    // Test Case 1: Circular list [1, 2, 3] -> circular
    {
        Node* head = createCircularList(std::vector<int>{1, 2, 3});
        assert(isCircular(head) == true);
        freeCircularList(head);
    }

    // Test Case 2: Linear list [1, 2, 3] -> not circular
    {
        Node* n1 = new Node(1);
        Node* n2 = new Node(2);
        Node* n3 = new Node(3);
        n1->next = n2;
        n2->next = n3;

        assert(isCircular(n1) == false);

        delete n3;
        delete n2;
        delete n1;
    }

    // Test Case 3: Single node circular
    {
        Node* n1 = new Node(42);
        n1->next = n1;
        assert(isCircular(n1) == true);
        n1->next = nullptr;
        delete n1;
    }

    // Test Case 4: Nullptr is considered circular by convention
    assert(isCircular(nullptr) == true);

    std::cout << "[PASS] 5_linklist/15_Check_If_Circular_LL: all tests passed!\n";
    return 0;
}
