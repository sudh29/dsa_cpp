#include <cassert>
#include <iostream>
#include <span>
#include <vector>

/**
 * Problem: Check If Linked List is Palindrome
 * Module: 5_linklist
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 *
 * Description:
 * Determines whether a singly linked list is a palindrome by reversing the second half
 * in-place, comparing halves, and restoring the list structure.
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
    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;
        Node* slow = head;
        Node* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* secondHalf = reverse(slow->next);
        Node* p1 = head;
        Node* p2 = secondHalf;
        bool isPal = true;

        while (p2) {
            if (p1->data != p2->data) {
                isPal = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        slow->next = reverse(secondHalf); // restore original list
        return isPal;
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

int main() {
    Solution sol;

    // Test Case 1: Even palindrome [1, 2, 2, 1]
    {
        Node* head = createList(std::vector<int>{1, 2, 2, 1});
        assert(sol.isPalindrome(head) == true);
        freeList(head);
    }

    // Test Case 2: Odd palindrome [1, 2, 3, 2, 1]
    {
        Node* head = createList(std::vector<int>{1, 2, 3, 2, 1});
        assert(sol.isPalindrome(head) == true);
        freeList(head);
    }

    // Test Case 3: Non-palindrome [1, 2, 3, 4]
    {
        Node* head = createList(std::vector<int>{1, 2, 3, 4});
        assert(sol.isPalindrome(head) == false);
        freeList(head);
    }

    // Test Case 4: Single node
    {
        Node* head = createList(std::vector<int>{42});
        assert(sol.isPalindrome(head) == true);
        freeList(head);
    }

    // Test Case 5: Nullptr
    assert(sol.isPalindrome(nullptr) == true);

    std::cout << "[PASS] 5_linklist/17_Check_if_LL_is_Palindrome: all tests passed!\n";
    return 0;
}
