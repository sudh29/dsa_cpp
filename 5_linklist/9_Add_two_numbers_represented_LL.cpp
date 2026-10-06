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

    Node* addTwoLists(Node* first, Node* second) {
        first = reverse(first);
        second = reverse(second);

        Node* dummy = new Node(0);
        Node* cur = dummy;
        int carry = 0;

        while (first || second || carry) {
            int sum = carry;
            if (first) { sum += first->data; first = first->next; }
            if (second) { sum += second->data; second = second->next; }
            carry = sum / 10;
            cur->next = new Node(sum % 10);
            cur = cur->next;
        }
        return reverse(dummy->next);
    }
};

int main() {
    Node* a = new Node(4); a->next = new Node(5); // 45
    Node* b = new Node(3); b->next = new Node(4); b->next->next = new Node(5); // 345

    Solution sol;
    Node* sum = sol.addTwoLists(a, b);
    cout << "Sum of lists: ";
    while (sum) { cout << sum->data; sum = sum->next; }
    cout << endl;
    return 0;
}
