#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Move Last Element to Front of a Linked List
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Moves the last node of a singly linked list to the front of the list.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

Node* moveToFront(Node* head) {
    if (!head || !head->next) return head;
    Node* secLast = nullptr;
    Node* last = head;

    while (last->next != nullptr) {
        secLast = last;
        last = last->next;
    }

    secLast->next = nullptr;
    last->next = head;
    return last;
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

std::vector<int> toVector(const Node* head) {
    std::vector<int> res;
    while (head != nullptr) {
        res.push_back(head->data);
        head = head->next;
    }
    return res;
}

int main() {
    // Test Case 1: [1, 2, 3, 4] -> [4, 1, 2, 3]
    {
        Node* head = createList(std::vector<int>{1, 2, 3, 4});
        head = moveToFront(head);
        assert(toVector(head) == (std::vector<int>{4, 1, 2, 3}));
        freeList(head);
    }

    // Test Case 2: 2 nodes [10, 20] -> [20, 10]
    {
        Node* head = createList(std::vector<int>{10, 20});
        head = moveToFront(head);
        assert(toVector(head) == (std::vector<int>{20, 10}));
        freeList(head);
    }

    // Test Case 3: 1 node [42] -> [42]
    {
        Node* head = createList(std::vector<int>{42});
        head = moveToFront(head);
        assert(toVector(head) == (std::vector<int>{42}));
        freeList(head);
    }

    // Test Case 4: Nullptr
    assert(moveToFront(nullptr) == nullptr);

    std::cout << "[PASS] 5_linklist/7_Move_last_element_to_front_LL: all tests passed!\n";
    return 0;
}
