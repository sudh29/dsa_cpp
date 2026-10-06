#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void deleteNode(Node** head, int key) {
    if (*head == nullptr) return;
    Node *prev = nullptr, *cur = *head;

    while (cur->data != key) {
        if (cur->next == *head) return;
        prev = cur;
        cur = cur->next;
    }

    if (cur->next == *head && prev == nullptr) {
        *head = nullptr;
        delete cur;
        return;
    }

    if (cur == *head) {
        prev = *head;
        while (prev->next != *head) prev = prev->next;
        *head = cur->next;
        prev->next = *head;
    } else if (cur->next == *head) {
        prev->next = *head;
    } else {
        prev->next = cur->next;
    }
    delete cur;
}

void reverse(Node** head_ref) {
    if (*head_ref == nullptr) return;
    Node *prev = nullptr, *cur = *head_ref, *nxt;
    Node *last = *head_ref;
    while (last->next != *head_ref) last = last->next;

    do {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    } while (cur != *head_ref);

    (*head_ref)->next = prev;
    *head_ref = prev;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;

    reverse(&head);
    cout << "Reversed circular LL head: " << head->data << endl;
    deleteNode(&head, 2);
    cout << "Deleted node 2, head is: " << head->data << endl;
    return 0;
}
