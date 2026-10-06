#include <cassert>
#include <iostream>
#include <span>
#include <unordered_set>
#include <vector>

/**
 * Problem: Remove Duplicates from an Unsorted Linked List
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(n) hash set
 *
 * Description:
 * Removes duplicate nodes from an unsorted singly linked list in a single pass
 * using an unordered set while freeing deleted nodes.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* removeDuplicates(Node* head) {
        if (!head) return nullptr;
        std::unordered_set<int> seen;
        Node* cur = head;
        Node* prev = nullptr;

        while (cur != nullptr) {
            if (seen.contains(cur->data)) {
                prev->next = cur->next;
                delete cur;
            } else {
                seen.insert(cur->data);
                prev = cur;
            }
            cur = prev->next;
        }
        return head;
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

    // Test Case 1: Unsorted duplicates [5, 2, 2, 4] -> [5, 2, 4]
    {
        Node* head = createList(std::vector<int>{5, 2, 2, 4});
        head = sol.removeDuplicates(head);
        assert(toVector(head) == (std::vector<int>{5, 2, 4}));
        freeList(head);
    }

    // Test Case 2: All identical [3, 3, 3, 3] -> [3]
    {
        Node* head = createList(std::vector<int>{3, 3, 3, 3});
        head = sol.removeDuplicates(head);
        assert(toVector(head) == (std::vector<int>{3}));
        freeList(head);
    }

    // Test Case 3: Already unique [1, 5, 2, 9] -> [1, 5, 2, 9]
    {
        Node* head = createList(std::vector<int>{1, 5, 2, 9});
        head = sol.removeDuplicates(head);
        assert(toVector(head) == (std::vector<int>{1, 5, 2, 9}));
        freeList(head);
    }

    // Test Case 4: Nullptr
    assert(sol.removeDuplicates(nullptr) == nullptr);

    std::cout << "[PASS] 5_linklist/6_Remove_duplicates_from_an_unsorted_LL: all tests passed!\n";
    return 0;
}
