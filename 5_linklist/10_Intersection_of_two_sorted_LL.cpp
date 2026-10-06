#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* findIntersection(Node* head1, Node* head2) {
    Node* dummy = new Node(0);
    Node* tail = dummy;

    while (head1 && head2) {
        if (head1->data == head2->data) {
            tail->next = new Node(head1->data);
            tail = tail->next;
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data < head2->data) {
            head1 = head1->next;
        } else {
            head2 = head2->next;
        }
    }
    return dummy->next;
}

int main() {
    Node* h1 = new Node(1); h1->next = new Node(2); h1->next->next = new Node(3);
    Node* h2 = new Node(2); h2->next = new Node(3); h2->next->next = new Node(4);

    Node* inter = findIntersection(h1, h2);
    cout << "Intersection of sorted LL: ";
    while (inter) { cout << inter->data << " "; inter = inter->next; }
    cout << endl;
    return 0;
}
