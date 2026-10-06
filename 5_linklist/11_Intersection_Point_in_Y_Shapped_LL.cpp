#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Intersection Point in Y Shaped Linked Lists
 * Module: 5_linklist
 * Time Complexity: O(N + M)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Finds the data of the first common node where two singly linked lists merge into a Y-shape.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

int intersectPoint(Node* head1, Node* head2) {
    if (!head1 || !head2) return -1;
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == nullptr) ? head2 : ptr1->next;
        ptr2 = (ptr2 == nullptr) ? head1 : ptr2->next;
    }
    return ptr1 ? ptr1->data : -1;
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test Case 1: Intersecting lists at node 15
    {
        Node* common = new Node(15);
        common->next = new Node(30);

        Node* h1 = new Node(3);
        h1->next = new Node(6);
        h1->next->next = common;

        Node* h2 = new Node(10);
        h2->next = common;

        assert(intersectPoint(h1, h2) == 15);

        // Safely unmerge before deallocation to prevent double-free
        h2->next = nullptr;
        freeList(h1); // frees 3, 6, 15, 30
        freeList(h2); // frees 10
    }

    // Test Case 2: Non-intersecting lists
    {
        Node* h1 = new Node(1);
        Node* h2 = new Node(2);

        assert(intersectPoint(h1, h2) == -1);

        freeList(h1);
        freeList(h2);
    }

    // Test Case 3: Same list (head is intersection)
    {
        Node* h1 = new Node(42);
        assert(intersectPoint(h1, h1) == 42);
        freeList(h1);
    }

    // Test Case 4: Nullptr
    assert(intersectPoint(nullptr, nullptr) == -1);

    std::cout << "[PASS] 5_linklist/11_Intersection_Point_in_Y_Shapped_LL: all tests passed!\n";
    return 0;
}
