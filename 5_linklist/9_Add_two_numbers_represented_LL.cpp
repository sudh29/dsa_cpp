#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Add Two Numbers Represented as Linked Lists
 * Module: 5_linklist
 * Time Complexity: O(N + M)
 * Space Complexity: O(max(N, M))
 *
 * Description:
 * Adds two numbers represented by linked lists where digits are stored in normal order.
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
    Node* addTwoLists(Node* first, Node* second) {
        Node* h1 = reverse(first);
        Node* h2 = reverse(second);
        Node* p1 = h1;
        Node* p2 = h2;

        Node* dummy = new Node(0);
        Node* cur = dummy;
        int carry = 0;

        while (p1 || p2 || carry) {
            int sum = carry;
            if (p1) {
                sum += p1->data;
                p1 = p1->next;
            }
            if (p2) {
                sum += p2->data;
                p2 = p2->next;
            }
            carry = sum / 10;
            cur->next = new Node(sum % 10);
            cur = cur->next;
        }

        Node* result = reverse(dummy->next);
        delete dummy;

        // Restore original lists
        reverse(h1);
        reverse(h2);

        return result;
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

    // Test Case 1: 45 + 345 = 390
    {
        Node* a = createList(std::vector<int>{4, 5});
        Node* b = createList(std::vector<int>{3, 4, 5});
        Node* sum = sol.addTwoLists(a, b);
        assert(toVector(sum) == (std::vector<int>{3, 9, 0}));
        freeList(a);
        freeList(b);
        freeList(sum);
    }

    // Test Case 2: 99 + 1 = 100
    {
        Node* a = createList(std::vector<int>{9, 9});
        Node* b = createList(std::vector<int>{1});
        Node* sum = sol.addTwoLists(a, b);
        assert(toVector(sum) == (std::vector<int>{1, 0, 0}));
        freeList(a);
        freeList(b);
        freeList(sum);
    }

    // Test Case 3: 0 + 0 = 0
    {
        Node* a = createList(std::vector<int>{0});
        Node* b = createList(std::vector<int>{0});
        Node* sum = sol.addTwoLists(a, b);
        assert(toVector(sum) == (std::vector<int>{0}));
        freeList(a);
        freeList(b);
        freeList(sum);
    }

    std::cout << "[PASS] 5_linklist/9_Add_two_numbers_represented_LL: all tests passed!\n";
    return 0;
}
