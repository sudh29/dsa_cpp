#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Remove Duplicate Elements from Sorted Linked List
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Removes duplicate nodes from a sorted singly linked list so that each element appears once.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

Node* removeDuplicates(Node* head) {
    Node* cur = head;
    while (cur && cur->next) {
        if (cur->data == cur->next->data) {
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        } else {
            cur = cur->next;
        }
    }
    return head;
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
    // Test Case 1: Multiple duplicates [2, 2, 4, 5] -> [2, 4, 5]
    {
        Node* head = createList(std::vector<int>{2, 2, 4, 5});
        head = removeDuplicates(head);
        assert(toVector(head) == (std::vector<int>{2, 4, 5}));
        freeList(head);
    }

    // Test Case 2: All identical [1, 1, 1, 1] -> [1]
    {
        Node* head = createList(std::vector<int>{1, 1, 1, 1});
        head = removeDuplicates(head);
        assert(toVector(head) == (std::vector<int>{1}));
        freeList(head);
    }

    // Test Case 3: No duplicates [1, 2, 3] -> [1, 2, 3]
    {
        Node* head = createList(std::vector<int>{1, 2, 3});
        head = removeDuplicates(head);
        assert(toVector(head) == (std::vector<int>{1, 2, 3}));
        freeList(head);
    }

    // Test Case 4: Empty list
    assert(removeDuplicates(nullptr) == nullptr);

    std::cout << "[PASS] 5_linklist/5_Remove_duplicate_element_from_sorted_LL: all tests passed!\n";
    return 0;
}
