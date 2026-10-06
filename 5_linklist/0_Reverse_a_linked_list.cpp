#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Reverse a Linked List (Iterative)
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Reverses a singly linked list in-place by updating pointer references.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* cur = head;
        Node* nxt = nullptr;
        while (cur != nullptr) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};

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
    Solution sol;

    // Test Case 1: Standard 4-element list
    {
        Node* head = createList(std::vector<int>{1, 2, 3, 4});
        head = sol.reverseList(head);
        assert(toVector(head) == (std::vector<int>{4, 3, 2, 1}));
        freeList(head);
    }

    // Test Case 2: Single-element list
    {
        Node* head = createList(std::vector<int>{42});
        head = sol.reverseList(head);
        assert(toVector(head) == (std::vector<int>{42}));
        freeList(head);
    }

    // Test Case 3: Empty list
    {
        Node* head = sol.reverseList(nullptr);
        assert(head == nullptr);
    }

    std::cout << "[PASS] 5_linklist/0_Reverse_a_linked_list: all tests passed!\n";
    return 0;
}
