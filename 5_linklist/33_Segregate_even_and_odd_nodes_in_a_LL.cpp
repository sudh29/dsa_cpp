#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Segregate Even and Odd Nodes in a Linked List
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Modifies the linked list such that all even nodes appear before all odd nodes
 * while preserving their relative order.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* divide(Node* head) {
        Node* evenStart = nullptr;
        Node* evenEnd = nullptr;
        Node* oddStart = nullptr;
        Node* oddEnd = nullptr;
        Node* cur = head;

        while (cur != nullptr) {
            int val = cur->data;
            if (val % 2 == 0) {
                if (!evenStart) {
                    evenStart = cur;
                    evenEnd = evenStart;
                } else {
                    evenEnd->next = cur;
                    evenEnd = evenEnd->next;
                }
            } else {
                if (!oddStart) {
                    oddStart = cur;
                    oddEnd = oddStart;
                } else {
                    oddEnd->next = cur;
                    oddEnd = oddEnd->next;
                }
            }
            cur = cur->next;
        }

        if (!evenStart || !oddStart) return head;

        evenEnd->next = oddStart;
        oddEnd->next = nullptr;
        return evenStart;
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

    // Test Case 1: [17, 15, 8, 9, 2, 4, 6] -> [8, 2, 4, 6, 17, 15, 9]
    {
        Node* head = createList(std::vector<int>{17, 15, 8, 9, 2, 4, 6});
        head = sol.divide(head);
        std::vector<int> expected = {8, 2, 4, 6, 17, 15, 9};
        assert(toVector(head) == expected);
        freeList(head);
    }

    // Test Case 2: All evens
    {
        Node* head = createList(std::vector<int>{2, 4, 6});
        head = sol.divide(head);
        assert(toVector(head) == (std::vector<int>{2, 4, 6}));
        freeList(head);
    }

    // Test Case 3: All odds
    {
        Node* head = createList(std::vector<int>{1, 3, 5});
        head = sol.divide(head);
        assert(toVector(head) == (std::vector<int>{1, 3, 5}));
        freeList(head);
    }

    // Test Case 4: Nullptr
    assert(sol.divide(nullptr) == nullptr);

    std::cout << "[PASS] 5_linklist/33_Segregate_even_and_odd_nodes_in_a_LL: all tests passed!\n";
    return 0;
}
