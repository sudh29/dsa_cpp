#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Delete Nodes Having Greater Value on Right in Linked List
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Deletes every node in the linked list that has a strictly greater node to its right.
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
    Node* compute(Node* head) {
        if (!head || !head->next) return head;
        head = reverse(head);
        Node* cur = head->next;
        int max_val = head->data;
        Node* prev = head;

        while (cur != nullptr) {
            if (cur->data >= max_val) {
                max_val = cur->data;
                prev = cur;
                cur = cur->next;
            } else {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }
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

    // Test Case 1: [12, 15, 10, 11, 5, 6, 2, 3] -> [15, 11, 6, 3]
    {
        Node* head = createList(std::vector<int>{12, 15, 10, 11, 5, 6, 2, 3});
        head = sol.compute(head);
        assert(toVector(head) == (std::vector<int>{15, 11, 6, 3}));
        freeList(head);
    }

    // Test Case 2: Strictly decreasing [10, 9, 8, 7] -> [10, 9, 8, 7]
    {
        Node* head = createList(std::vector<int>{10, 9, 8, 7});
        head = sol.compute(head);
        assert(toVector(head) == (std::vector<int>{10, 9, 8, 7}));
        freeList(head);
    }

    // Test Case 3: Strictly increasing [1, 2, 3, 4] -> [4]
    {
        Node* head = createList(std::vector<int>{1, 2, 3, 4});
        head = sol.compute(head);
        assert(toVector(head) == (std::vector<int>{4}));
        freeList(head);
    }

    // Test Case 4: Nullptr
    assert(sol.compute(nullptr) == nullptr);

    std::cout << "[PASS] 5_linklist/32_Delete_nodes_having_greater_value_on_right_LL: all tests passed!\n";
    return 0;
}
