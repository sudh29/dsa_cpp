#include <cassert>
#include <iostream>
#include <span>
#include <utility>
#include <vector>

/**
 * Problem: Find Pairs with Given Sum in Doubly Linked List
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Finds all pairs of nodes in a sorted doubly linked list whose data values sum to target.
 */

struct Node {
    int data;
    Node* next{nullptr};
    Node* prev{nullptr};
    explicit Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Solution {
public:
    std::vector<std::pair<int, int>> findPairsWithGivenSum(Node* head, int target) {
        std::vector<std::pair<int, int>> res;
        if (!head) return res;

        Node* first = head;
        Node* second = head;
        while (second->next != nullptr) {
            second = second->next;
        }

        while (first != second && second->next != first) {
            int sum = first->data + second->data;
            if (sum == target) {
                res.emplace_back(first->data, second->data);
                first = first->next;
                second = second->prev;
            } else if (sum < target) {
                first = first->next;
            } else {
                second = second->prev;
            }
        }
        return res;
    }
};

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
    Solution sol;

    // Test Case 1: [1, 2, 4, 5, 6, 8, 9] with target 7 -> (1, 6), (2, 5)
    {
        Node* head = createDLL(std::vector<int>{1, 2, 4, 5, 6, 8, 9});
        auto pairs = sol.findPairsWithGivenSum(head, 7);
        std::vector<std::pair<int, int>> expected = {{1, 6}, {2, 5}};
        assert(pairs == expected);
        freeDLL(head);
    }

    // Test Case 2: [1, 2, 4, 5] with target 6 -> (1, 5), (2, 4)
    {
        Node* head = createDLL(std::vector<int>{1, 2, 4, 5});
        auto pairs = sol.findPairsWithGivenSum(head, 6);
        std::vector<std::pair<int, int>> expected = {{1, 5}, {2, 4}};
        assert(pairs == expected);
        freeDLL(head);
    }

    // Test Case 3: No pairs
    {
        Node* head = createDLL(std::vector<int>{1, 2, 3});
        auto pairs = sol.findPairsWithGivenSum(head, 100);
        assert(pairs.empty());
        freeDLL(head);
    }

    // Test Case 4: Nullptr
    assert(sol.findPairsWithGivenSum(nullptr, 6).empty());

    std::cout << "[PASS] 5_linklist/20_Find_pairs_with_given_sum_in_doubly_LL: all tests passed!\n";
    return 0;
}
