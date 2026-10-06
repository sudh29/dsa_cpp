#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Reverse a Linked List in Groups of Given Size (K)
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(n/k) recursion stack
 *
 * Description:
 * Reverses every group of k contiguous nodes in a linked list.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* reverse(Node* head, int k) {
        if (!head || k <= 1) return head;
        Node* cur = head;
        Node* prev = nullptr;
        Node* nxt = nullptr;
        int count = 0;

        while (cur != nullptr && count < k) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            count++;
        }

        if (nxt != nullptr) {
            head->next = reverse(nxt, k);
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

    // Test Case 1: [1, 2, 3, 4, 5] with k = 2 -> [2, 1, 4, 3, 5]
    {
        Node* head = createList(std::vector<int>{1, 2, 3, 4, 5});
        head = sol.reverse(head, 2);
        assert(toVector(head) == (std::vector<int>{2, 1, 4, 3, 5}));
        freeList(head);
    }

    // Test Case 2: [1, 2, 3, 4] with k = 4 -> [4, 3, 2, 1]
    {
        Node* head = createList(std::vector<int>{1, 2, 3, 4});
        head = sol.reverse(head, 4);
        assert(toVector(head) == (std::vector<int>{4, 3, 2, 1}));
        freeList(head);
    }

    // Test Case 3: k = 1 (no change)
    {
        Node* head = createList(std::vector<int>{1, 2, 3});
        head = sol.reverse(head, 1);
        assert(toVector(head) == (std::vector<int>{1, 2, 3}));
        freeList(head);
    }

    // Test Case 4: nullptr
    assert(sol.reverse(nullptr, 3) == nullptr);

    std::cout << "[PASS] 5_linklist/1_Reverse_Linked_List_groups_given_size: all tests passed!\n";
    return 0;
}
