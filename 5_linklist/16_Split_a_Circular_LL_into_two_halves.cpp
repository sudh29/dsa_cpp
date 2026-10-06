#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Split a Circular Linked List into Two Halves
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Splits a circular linked list into two separate circular linked lists.
 * If there are odd nodes, the first list contains the extra node.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    void splitList(Node* head, Node** head1_ref, Node** head2_ref) {
        if (!head) return;
        Node* slow = head;
        Node* fast = head;

        while (fast->next != head && fast->next->next != head) {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast->next->next == head) {
            fast = fast->next;
        }

        *head1_ref = head;
        if (head->next != head) {
            *head2_ref = slow->next;
        }
        fast->next = slow->next;
        slow->next = head;
    }
};

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
    Solution sol;

    // Test Case 1: Even length [1, 2, 3, 4] -> [1, 2] and [3, 4]
    {
        Node* head = createCircularList(std::vector<int>{1, 2, 3, 4});
        Node* h1 = nullptr;
        Node* h2 = nullptr;
        sol.splitList(head, &h1, &h2);

        assert(toCircularVector(h1) == (std::vector<int>{1, 2}));
        assert(toCircularVector(h2) == (std::vector<int>{3, 4}));

        freeCircularList(h1);
        freeCircularList(h2);
    }

    // Test Case 2: Odd length [1, 2, 3] -> [1, 2] and [3]
    {
        Node* head = createCircularList(std::vector<int>{1, 2, 3});
        Node* h1 = nullptr;
        Node* h2 = nullptr;
        sol.splitList(head, &h1, &h2);

        assert(toCircularVector(h1) == (std::vector<int>{1, 2}));
        assert(toCircularVector(h2) == (std::vector<int>{3}));

        freeCircularList(h1);
        freeCircularList(h2);
    }

    std::cout << "[PASS] 5_linklist/16_Split_a_Circular_LL_into_two_halves: all tests passed!\n";
    return 0;
}
