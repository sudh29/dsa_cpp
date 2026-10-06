#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Intersection of Two Sorted Linked Lists
 * Module: 5_linklist
 * Time Complexity: O(N + M)
 * Space Complexity: O(min(N, M)) for new intersection list
 *
 * Description:
 * Constructs a new linked list containing the common elements from two sorted linked lists.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

Node* findIntersection(Node* head1, Node* head2) {
    Node* dummy = new Node(0);
    Node* tail = dummy;

    while (head1 && head2) {
        if (head1->data == head2->data) {
            tail->next = new Node(head1->data);
            tail = tail->next;
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data < head2->data) {
            head1 = head1->next;
        } else {
            head2 = head2->next;
        }
    }

    Node* result = dummy->next;
    delete dummy;
    return result;
}

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
    // Test Case 1: [1, 2, 3] and [2, 3, 4] -> [2, 3]
    {
        Node* h1 = createList(std::vector<int>{1, 2, 3});
        Node* h2 = createList(std::vector<int>{2, 3, 4});
        Node* inter = findIntersection(h1, h2);
        assert(toVector(inter) == (std::vector<int>{2, 3}));
        freeList(h1);
        freeList(h2);
        freeList(inter);
    }

    // Test Case 2: Disjoint lists
    {
        Node* h1 = createList(std::vector<int>{1, 3, 5});
        Node* h2 = createList(std::vector<int>{2, 4, 6});
        Node* inter = findIntersection(h1, h2);
        assert(inter == nullptr);
        freeList(h1);
        freeList(h2);
    }

    // Test Case 3: One empty list
    {
        Node* h1 = createList(std::vector<int>{1, 2});
        Node* inter = findIntersection(h1, nullptr);
        assert(inter == nullptr);
        freeList(h1);
    }

    std::cout << "[PASS] 5_linklist/10_Intersection_of_two_sorted_LL: all tests passed!\n";
    return 0;
}
