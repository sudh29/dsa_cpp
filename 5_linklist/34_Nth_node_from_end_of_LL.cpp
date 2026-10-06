#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int getNthFromLast(Node *head, int n) {
    Node *first = head, *second = head;
    for (int i = 0; i < n; i++) {
        if (!first) return -1;
        first = first->next;
    }
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }
    return second ? second->data : -1;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "2nd from last node: " << getNthFromLast(head, 2) << endl;
    return 0;
}
