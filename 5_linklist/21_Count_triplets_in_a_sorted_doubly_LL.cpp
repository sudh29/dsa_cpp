#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Count Triplets in a Sorted Doubly Linked List with Given Sum
 * Module: 5_linklist
 * Time Complexity: O(n^2)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Counts the number of distinct triplets in a sorted doubly linked list whose sum is equal to x.
 */

struct Node {
    int data;
    Node* next{nullptr};
    Node* prev{nullptr};
    explicit Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

int countPairs(Node* first, Node* second, int value) {
    int count = 0;
    while (first != nullptr && second != nullptr && first != second && second->next != first) {
        int sum = first->data + second->data;
        if (sum == value) {
            count++;
            first = first->next;
            second = second->prev;
        } else if (sum > value) {
            second = second->prev;
        } else {
            first = first->next;
        }
    }
    return count;
}

int countTriplets(Node* head, int x) {
    if (!head || !head->next || !head->next->next) return 0;
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }

    int count = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        Node* first = cur->next;
        count += countPairs(first, last, x - cur->data);
    }
    return count;
}

Node* createDLL(std::span<const int> values) {
    if (values.empty()) return nullptr;
    Node* head = new Node(values[0]);
    Node* cur = head;
    for (size_t i = 1; i < values.size(); ++i) {
        Node* node = new Node(values[i]);
        cur->next = node;
        node->prev = cur;
        cur = node;
    }
    return head;
}

void freeDLL(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test Case 1: [1, 2, 4, 5, 6, 8, 9] with x = 17 -> (2, 6, 9), (4, 5, 8) -> 2
    {
        Node* head = createDLL(std::vector<int>{1, 2, 4, 5, 6, 8, 9});
        assert(countTriplets(head, 17) == 2);
        freeDLL(head);
    }

    // Test Case 2: [1, 2, 4, 5, 6] with x = 9 -> (1, 2, 6) -> 1
    {
        Node* head = createDLL(std::vector<int>{1, 2, 4, 5, 6});
        assert(countTriplets(head, 9) == 1);
        freeDLL(head);
    }

    // Test Case 3: Less than 3 nodes
    {
        Node* head = createDLL(std::vector<int>{1, 2});
        assert(countTriplets(head, 3) == 0);
        freeDLL(head);
    }

    // Test Case 4: Nullptr
    assert(countTriplets(nullptr, 5) == 0);

    std::cout << "[PASS] 5_linklist/21_Count_triplets_in_a_sorted_doubly_LL: all tests passed!\n";
    return 0;
}
