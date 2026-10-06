#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* reverse(Node* head) {
        Node *prev = nullptr, *cur = head, *nxt = nullptr;
        while (cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;
        Node *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *secondHalf = reverse(slow->next);
        Node *p1 = head, *p2 = secondHalf;
        bool isPal = true;

        while (p2) {
            if (p1->data != p2->data) {
                isPal = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        slow->next = reverse(secondHalf);
        return isPal;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    Solution sol;
    cout << "Is LL palindrome: " << (sol.isPalindrome(head) ? "Yes" : "No") << endl;
    return 0;
}
