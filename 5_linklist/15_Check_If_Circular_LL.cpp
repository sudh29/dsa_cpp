#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool isCircular(Node *head) {
    if (!head) return true;
    Node *cur = head->next;
    while (cur != nullptr && cur != head) {
        cur = cur->next;
    }
    return cur == head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;

    cout << "Is circular: " << (isCircular(head) ? "Yes" : "No") << endl;
    return 0;
}
