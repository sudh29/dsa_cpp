#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Rotate a Doubly Linked List by P Positions
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Rotates a doubly linked list counter-clockwise by p nodes.
 */

struct Node {
    int data;
    Node* next{nullptr};
    Node* prev{nullptr};
    explicit Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Solution {
public:
    Node* rotateDLL(Node* start, int p) {
        if (!start || p == 0) return start;
        Node* cur = start;
        int count = 1;
        while (count < p && cur != nullptr) {
            cur = cur->next;
            count++;
        }
        if (!cur || !cur->next) return start;

        Node* nthNode = cur;
        Node* tail = cur;
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        tail->next = start;
        start->prev = tail;
        start = nthNode->next;
        start->prev = nullptr;
        nthNode->next = nullptr;
        return start;
    }
};

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
    Solution sol;

    // Test Case 1: [1, 2, 3, 4, 5] rotate by 2 -> [3, 4, 5, 1, 2]
    {
        Node* head = createDLL(std::vector<int>{1, 2, 3, 4, 5});
        head = sol.rotateDLL(head, 2);
        assert(toVector(head) == (std::vector<int>{3, 4, 5, 1, 2}));
        freeDLL(head);
    }

    // Test Case 2: [1, 2, 3, 4] rotate by 2 -> [3, 4, 1, 2]
    {
        Node* head = createDLL(std::vector<int>{1, 2, 3, 4});
        head = sol.rotateDLL(head, 2);
        assert(toVector(head) == (std::vector<int>{3, 4, 1, 2}));
        freeDLL(head);
    }

    // Test Case 3: Rotate by 0 (no change)
    {
        Node* head = createDLL(std::vector<int>{1, 2, 3});
        head = sol.rotateDLL(head, 0);
        assert(toVector(head) == (std::vector<int>{1, 2, 3}));
        freeDLL(head);
    }

    // Test Case 4: Nullptr
    assert(sol.rotateDLL(nullptr, 3) == nullptr);

    std::cout << "[PASS] 5_linklist/23_Rotate_doubly_LL: all tests passed!\n";
    return 0;
}
