#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Remove Loop in Linked List
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Detects and breaks a loop in a linked list so it becomes a standard linear list.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    void removeLoop(Node* head) {
        if (!head || !head->next) return;
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        if (slow == fast) {
            slow = head;
            if (slow == fast) {
                while (fast->next != slow) {
                    fast = fast->next;
                }
            } else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            fast->next = nullptr;
        }
    }

    [[nodiscard]] bool hasLoop(Node* head) const {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
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

    // Test Case 1: 3-node list with loop to node 2
    {
        Node* n1 = new Node(1);
        Node* n2 = new Node(2);
        Node* n3 = new Node(3);
        n1->next = n2;
        n2->next = n3;
        n3->next = n2; // loop

        assert(sol.hasLoop(n1) == true);
        sol.removeLoop(n1);
        assert(sol.hasLoop(n1) == false);
        assert(n3->next == nullptr);

        freeList(n1);
    }

    // Test Case 2: Loop to head node
    {
        Node* n1 = new Node(10);
        Node* n2 = new Node(20);
        n1->next = n2;
        n2->next = n1; // circular loop to head

        assert(sol.hasLoop(n1) == true);
        sol.removeLoop(n1);
        assert(sol.hasLoop(n1) == false);
        assert(n2->next == nullptr);

        freeList(n1);
    }

    // Test Case 3: List without loop
    {
        Node* n1 = new Node(100);
        Node* n2 = new Node(200);
        n1->next = n2;

        sol.removeLoop(n1);
        assert(sol.hasLoop(n1) == false);
        assert(n1->next == n2);

        freeList(n1);
    }

    std::cout << "[PASS] 5_linklist/3_Remove_loop_LL: all tests passed!\n";
    return 0;
}
