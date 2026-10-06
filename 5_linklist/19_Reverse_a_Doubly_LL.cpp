#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

Node* reverseDLL(Node *head) {
    if (!head || !head->next) return head;
    Node *cur = head, *temp = nullptr;
    while (cur != nullptr) {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }
    if (temp != nullptr) {
        head = temp->prev;
    }
    return head;
}

int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;

    head = reverseDLL(head);
    cout << "Reversed DLL: ";
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
    return 0;
}
