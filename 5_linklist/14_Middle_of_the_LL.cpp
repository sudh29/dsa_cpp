#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Middle of the Linked List
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Finds the middle node of a singly linked list using fast and slow pointers.
 * If there are two middle nodes, returns the second middle node.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* middleNode(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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

int main() {
    Solution sol;

    // Test Case 1: Odd length [1, 2, 3, 4, 5] -> middle is 3
    {
        Node* head = createList(std::vector<int>{1, 2, 3, 4, 5});
        Node* mid = sol.middleNode(head);
        assert(mid != nullptr && mid->data == 3);
        freeList(head);
    }

    // Test Case 2: Even length [1, 2, 3, 4, 5, 6] -> second middle is 4
    {
        Node* head = createList(std::vector<int>{1, 2, 3, 4, 5, 6});
        Node* mid = sol.middleNode(head);
        assert(mid != nullptr && mid->data == 4);
        freeList(head);
    }

    // Test Case 3: Single node [42] -> middle is 42
    {
        Node* head = createList(std::vector<int>{42});
        Node* mid = sol.middleNode(head);
        assert(mid != nullptr && mid->data == 42);
        freeList(head);
    }

    // Test Case 4: Nullptr
    assert(sol.middleNode(nullptr) == nullptr);

    std::cout << "[PASS] 5_linklist/14_Middle_of_the_LL: all tests passed!\n";
    return 0;
}
