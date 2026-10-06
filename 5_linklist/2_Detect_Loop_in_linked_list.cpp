#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Detect Loop in Linked List (Floyd's Tortoise and Hare)
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Detects whether a linked list contains a cycle using fast and slow pointers.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    [[nodiscard]] bool detectLoop(Node* head) const {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
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

    // Test Case 1: List with loop
    {
        Node* n1 = new Node(1);
        Node* n2 = new Node(2);
        Node* n3 = new Node(3);
        n1->next = n2;
        n2->next = n3;
        n3->next = n2; // loop created

        assert(sol.detectLoop(n1) == true);

        // Break loop before deallocation to prevent infinite loop / leak
        n3->next = nullptr;
        freeList(n1);
    }

    // Test Case 2: List without loop
    {
        Node* n1 = new Node(10);
        Node* n2 = new Node(20);
        n1->next = n2;

        assert(sol.detectLoop(n1) == false);
        freeList(n1);
    }

    // Test Case 3: Single node without loop
    {
        Node* n1 = new Node(42);
        assert(sol.detectLoop(n1) == false);
        freeList(n1);
    }

    // Test Case 4: Single node with self loop
    {
        Node* n1 = new Node(42);
        n1->next = n1;
        assert(sol.detectLoop(n1) == true);
        n1->next = nullptr;
        freeList(n1);
    }

    // Test Case 5: Empty list
    assert(sol.detectLoop(nullptr) == false);

    std::cout << "[PASS] 5_linklist/2_Detect_Loop_in_linked_list: all tests passed!\n";
    return 0;
}
