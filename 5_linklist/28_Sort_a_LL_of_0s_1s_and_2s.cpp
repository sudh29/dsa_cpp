#include <array>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Sort a Linked List of 0s, 1s, and 2s
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Segregates and sorts a linked list containing only values 0, 1, and 2 in non-decreasing order.
 */

struct Node {
    int data;
    Node* next{nullptr};
    explicit Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* segregate(Node* head) {
        std::array<int, 3> count{};
        Node* ptr = head;
        while (ptr != nullptr) {
            if (ptr->data >= 0 && ptr->data <= 2) {
                count[ptr->data]++;
            }
            ptr = ptr->next;
        }

        size_t i = 0;
        ptr = head;
        while (ptr != nullptr) {
            if (count[i] == 0) {
                ++i;
            } else {
                ptr->data = static_cast<int>(i);
                count[i]--;
                ptr = ptr->next;
            }
        }
        return head;
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

    // Test Case 1: [1, 2, 2, 0] -> [0, 1, 2, 2]
    {
        Node* head = createList(std::vector<int>{1, 2, 2, 0});
        head = sol.segregate(head);
        assert(toVector(head) == (std::vector<int>{0, 1, 2, 2}));
        freeList(head);
    }

    // Test Case 2: [2, 1, 0] -> [0, 1, 2]
    {
        Node* head = createList(std::vector<int>{2, 1, 0});
        head = sol.segregate(head);
        assert(toVector(head) == (std::vector<int>{0, 1, 2}));
        freeList(head);
    }

    // Test Case 3: Already sorted
    {
        Node* head = createList(std::vector<int>{0, 0, 1, 2});
        head = sol.segregate(head);
        assert(toVector(head) == (std::vector<int>{0, 0, 1, 2}));
        freeList(head);
    }

    // Test Case 4: Nullptr
    assert(sol.segregate(nullptr) == nullptr);

    std::cout << "[PASS] 5_linklist/28_Sort_a_LL_of_0s_1s_and_2s: all tests passed!\n";
    return 0;
}
