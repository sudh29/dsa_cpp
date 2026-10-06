#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* moveToFront(Node* head) {
    if (!head || !head->next) return head;
    Node* secLast = nullptr;
    Node* last = head;

    while (last->next != nullptr) {
        secLast = last;
        last = last->next;
    }

    secLast->next = nullptr;
    last->next = head;
    return last;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = moveToFront(head);
    cout << "Moved last to front: ";
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
    return 0;
}
