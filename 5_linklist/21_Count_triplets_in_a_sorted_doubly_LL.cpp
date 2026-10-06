#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

int countPairs(Node *first, Node *second, int value) {
    int count = 0;
    while (first != nullptr && second != nullptr && first != second && second->next != first) {
        if ((first->data + second->data) == value) {
            count++;
            first = first->next;
            second = second->prev;
        } else if ((first->data + second->data) > value) {
            second = second->prev;
        } else {
            first = first->next;
        }
    }
    return count;
}

int countTriplets(Node *head, int x) {
    if (!head) return 0;
    Node *cur, *first, *last = head;
    int count = 0;
    while (last->next != nullptr) last = last->next;

    for (cur = head; cur != nullptr; cur = cur->next) {
        first = cur->next;
        count += countPairs(first, last, x - cur->data);
    }
    return count;
}

int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(4);
    Node* n4 = new Node(5);
    Node* n5 = new Node(6);
    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;

    cout << "Triplets summing to 9 in DLL: " << countTriplets(head, 9) << endl;
    return 0;
}
