#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    void splitList(Node *head, Node **head1_ref, Node **head2_ref) {
        if (!head) return;
        Node *slow = head, *fast = head;

        while (fast->next != head && fast->next->next != head) {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast->next->next == head) {
            fast = fast->next;
        }

        *head1_ref = head;
        if (head->next != head) {
            *head2_ref = slow->next;
        }
        fast->next = slow->next;
        slow->next = head;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    Node *h1 = nullptr, *h2 = nullptr;
    Solution sol;
    sol.splitList(head, &h1, &h2);
    cout << "Split circular list into h1 (head " << h1->data << ") and h2 (head " << h2->data << ")\n";
    return 0;
}
