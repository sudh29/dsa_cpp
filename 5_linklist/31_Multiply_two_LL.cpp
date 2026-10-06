#include <cassert>
#include <cstdint>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Multiply Two Numbers Represented as Linked Lists
 * Module: 5_linklist
 * Time Complexity: O(N + M)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Multiplies two numbers represented by linked lists modulo 10^9 + 7.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

int64_t multiplyTwoList(Node* first, Node* second) {
    int64_t num1 = 0;
    int64_t num2 = 0;
    constexpr int64_t MOD = 1000000007;

    while (first != nullptr) {
        num1 = (num1 * 10 + first->data) % MOD;
        first = first->next;
    }
    while (second != nullptr) {
        num2 = (num2 * 10 + second->data) % MOD;
        second = second->next;
    }
    return (num1 * num2) % MOD;
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

int main() {
    // Test Case 1: 32 * 2 = 64
    {
        Node* a = createList(std::vector<int>{3, 2});
        Node* b = createList(std::vector<int>{2});
        assert(multiplyTwoList(a, b) == 64);
        freeList(a);
        freeList(b);
    }

    // Test Case 2: 100 * 0 = 0
    {
        Node* a = createList(std::vector<int>{1, 0, 0});
        Node* b = createList(std::vector<int>{0});
        assert(multiplyTwoList(a, b) == 0);
        freeList(a);
        freeList(b);
    }

    // Test Case 3: 123 * 45 = 5535
    {
        Node* a = createList(std::vector<int>{1, 2, 3});
        Node* b = createList(std::vector<int>{4, 5});
        assert(multiplyTwoList(a, b) == 5535);
        freeList(a);
        freeList(b);
    }

    std::cout << "[PASS] 5_linklist/31_Multiply_two_LL: all tests passed!\n";
    return 0;
}
