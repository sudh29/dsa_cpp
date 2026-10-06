#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int intersectPoint(Node* head1, Node* head2) {
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == nullptr) ? head2 : ptr1->next;
        ptr2 = (ptr2 == nullptr) ? head1 : ptr2->next;
    }
    return ptr1 ? ptr1->data : -1;
}

int main() {
    Node* common = new Node(15);
    common->next = new Node(30);

    Node* h1 = new Node(3);
    h1->next = new Node(6);
    h1->next->next = common;

    Node* h2 = new Node(10);
    h2->next = common;

    cout << "Intersection point data: " << intersectPoint(h1, h2) << endl;
    return 0;
}
