#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Deletion and Reverse in Circular Linked List
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Deletes a given key from a circular linked list and reverses the circular linked list.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

void deleteNode(Node** head, int key) {
    if (!head || *head == nullptr) return;
    Node* prev = nullptr;
    Node* cur = *head;

    while (cur->data != key) {
        if (cur->next == *head) return; // key not found
        prev = cur;
        cur = cur->next;
    }

    // Only one node in circular list
    if (cur->next == *head && prev == nullptr) {
        *head = nullptr;
        delete cur;
        return;
    }

    if (cur == *head) {
        prev = *head;
        while (prev->next != *head) prev = prev->next;
        *head = cur->next;
        prev->next = *head;
    } else {
        prev->next = cur->next;
    }
    delete cur;
}

void reverse(Node** head_ref) {
    if (!head_ref || *head_ref == nullptr) return;
    Node* prev = nullptr;
    Node* cur = *head_ref;
    Node* nxt = nullptr;

    do {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    } while (cur != *head_ref);

    (*head_ref)->next = prev;
    *head_ref = prev;
}

Node* createCircularList(std::span<const int> values) {
    if (values.empty()) return nullptr;
    Node* head = new Node(values[0]);
    Node* cur = head;
    for (size_t i = 1; i < values.size(); ++i) {
        cur->next = new Node(values[i]);
        cur = cur->next;
    }
    cur->next = head;
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

std::vector<int> toCircularVector(const Node* head) {
    std::vector<int> res;
    if (!head) return res;
    const Node* cur = head;
    do {
        res.push_back(cur->data);
        cur = cur->next;
    } while (cur != nullptr && cur != head);
    return res;
}

int main() {
    // Test Case 1: Delete node and reverse [1, 2, 3, 4] -> delete 2 -> [1, 3, 4] -> reverse -> [4, 3, 1]
    {
        Node* head = createCircularList(std::vector<int>{1, 2, 3, 4});
        deleteNode(&head, 2);
        assert(toCircularVector(head) == (std::vector<int>{1, 3, 4}));

        reverse(&head);
        assert(toCircularVector(head) == (std::vector<int>{4, 3, 1}));
        freeCircularList(head);
    }

    // Test Case 2: Delete head node
    {
        Node* head = createCircularList(std::vector<int>{10, 20, 30});
        deleteNode(&head, 10);
        assert(toCircularVector(head) == (std::vector<int>{20, 30}));
        freeCircularList(head);
    }

    // Test Case 3: Delete only node in list
    {
        Node* head = createCircularList(std::vector<int>{99});
        deleteNode(&head, 99);
        assert(head == nullptr);
    }

    std::cout << "[PASS] 5_linklist/18_Deletion_and_Reverse_LL: all tests passed!\n";
    return 0;
}
