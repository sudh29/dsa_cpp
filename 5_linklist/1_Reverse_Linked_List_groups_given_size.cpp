#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* reverse(Node* head, int k) {
        if (!head) return nullptr;
        Node* cur = head;
        Node* prev = nullptr;
        Node* nxt = nullptr;
        int count = 0;

        while (cur != nullptr && count < k) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            count++;
        }

        if (nxt != nullptr) {
            head->next = reverse(nxt, k);
        }
        return prev;
    }
};

void printList(Node* head) {
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution sol;
    head = sol.reverse(head, 2);
    cout << "Reversed in groups of 2: ";
    printList(head);
    return 0;
}
