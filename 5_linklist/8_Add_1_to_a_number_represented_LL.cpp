#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Add 1 to a Number Represented as Linked List
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Adds 1 to a number whose digits are stored in a singly linked list.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

class Solution {
private:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* cur = head;
        Node* nxt = nullptr;
        while (cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

public:
    Node* addOne(Node* head) {
        if (!head) return new Node(1);
        head = reverse(head);
        Node* cur = head;
        int carry = 1;

        while (cur && carry) {
            int sum = cur->data + carry;
            cur->data = sum % 10;
            carry = sum / 10;
            if (!cur->next && carry) {
                cur->next = new Node(carry);
                carry = 0;
            }
            cur = cur->next;
        }
        return reverse(head);
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

    // Test Case 1: 459 + 1 = 460
    {
        Node* head = createList(std::vector<int>{4, 5, 9});
        head = sol.addOne(head);
        assert(toVector(head) == (std::vector<int>{4, 6, 0}));
        freeList(head);
    }

    // Test Case 2: 999 + 1 = 1000
    {
        Node* head = createList(std::vector<int>{9, 9, 9});
        head = sol.addOne(head);
        assert(toVector(head) == (std::vector<int>{1, 0, 0, 0}));
        freeList(head);
    }

    // Test Case 3: 0 + 1 = 1
    {
        Node* head = createList(std::vector<int>{0});
        head = sol.addOne(head);
        assert(toVector(head) == (std::vector<int>{1}));
        freeList(head);
    }

    // Test Case 4: Nullptr -> creates node 1
    {
        Node* head = sol.addOne(nullptr);
        assert(toVector(head) == (std::vector<int>{1}));
        freeList(head);
    }

    std::cout << "[PASS] 5_linklist/8_Add_1_to_a_number_represented_LL: all tests passed!\n";
    return 0;
}
