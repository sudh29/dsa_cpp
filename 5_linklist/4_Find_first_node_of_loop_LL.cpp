#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Find First Node of Loop in Linked List
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Finds the starting node of the cycle in a linked list using Floyd's Tortoise and Hare.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* detectLoopStarting(Node* head) {
        if (!head || !head->next) return nullptr;
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return nullptr;

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;

    // Test Case 1: 3-node list with loop starting at node 2
    {
        Node* n1 = new Node(1);
        Node* n2 = new Node(2);
        Node* n3 = new Node(3);
        n1->next = n2;
        n2->next = n3;
        n3->next = n2; // loop starts at n2

        Node* start = sol.detectLoopStarting(n1);
        assert(start == n2);
        assert(start->data == 2);

        // Break loop and free
        n3->next = nullptr;
        freeList(n1);
    }

    // Test Case 2: No loop
    {
        Node* n1 = new Node(10);
        Node* n2 = new Node(20);
        n1->next = n2;

        assert(sol.detectLoopStarting(n1) == nullptr);
        freeList(n1);
    }

    // Test Case 3: Loop starting at head node
    {
        Node* n1 = new Node(100);
        Node* n2 = new Node(200);
        n1->next = n2;
        n2->next = n1;

        assert(sol.detectLoopStarting(n1) == n1);

        n2->next = nullptr;
        freeList(n1);
    }

    // Test Case 4: Nullptr
    assert(sol.detectLoopStarting(nullptr) == nullptr);

    std::cout << "[PASS] 5_linklist/4_Find_first_node_of_loop_LL: all tests passed!\n";
    return 0;
}
