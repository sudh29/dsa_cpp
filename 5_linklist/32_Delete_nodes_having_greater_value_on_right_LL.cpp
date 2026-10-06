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

    Node *compute(Node *head) {
        head = reverse(head);
        Node *cur = head;
        int max_val = head->data;
        Node *prev = head;
        cur = cur->next;

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

int main() {
    Node* head = new Node(12);
    head->next = new Node(15);
    head->next->next = new Node(10);
    head->next->next->next = new Node(11);

    Solution sol;
    head = sol.compute(head);
    cout << "Nodes after deleting rightward smaller: ";
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
    return 0;
}
