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

    Node* addOne(Node* head) {
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

int main() {
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(9); // 459 + 1 = 460

    Solution sol;
    head = sol.addOne(head);
    cout << "Added 1 to list: ";
    while (head) { cout << head->data; head = head->next; }
    cout << endl;
    return 0;
}
