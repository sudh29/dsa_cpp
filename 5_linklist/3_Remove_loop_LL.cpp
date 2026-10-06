#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    void removeLoop(Node* head) {
        if (!head || !head->next) return;
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        if (slow == fast) {
            slow = head;
            if (slow == fast) {
                while (fast->next != slow) fast = fast->next;
            } else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            fast->next = nullptr;
        }
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head->next; // loop

    Solution sol;
    sol.removeLoop(head);
    cout << "Loop removed successfully.\n";
    return 0;
}
