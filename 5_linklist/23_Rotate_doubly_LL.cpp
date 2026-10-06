#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Solution {
public:
    Node *rotateDLL(Node *start, int p) {
        if (!start || p == 0) return start;
        Node *cur = start;
        int count = 1;
        while (count < p && cur != nullptr) {
            cur = cur->next;
            count++;
        }
        if (!cur || !cur->next) return start;

        Node *nthNode = cur;
        Node *tail = cur;
        while (tail->next != nullptr) tail = tail->next;

        tail->next = start;
        start->prev = tail;
        start = nthNode->next;
        start->prev = nullptr;
        nthNode->next = nullptr;
        return start;
    }
};

int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;

    Solution sol;
    head = sol.rotateDLL(head, 2);
    cout << "Rotated DLL by 2: ";
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
    return 0;
}
