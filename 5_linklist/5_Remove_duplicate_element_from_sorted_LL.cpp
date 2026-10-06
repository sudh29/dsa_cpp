#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* removeDuplicates(Node* head) {
    Node* cur = head;
    while (cur && cur->next) {
        if (cur->data == cur->next->data) {
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    head = removeDuplicates(head);
    cout << "Deduplicated sorted list: ";
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
    return 0;
}
