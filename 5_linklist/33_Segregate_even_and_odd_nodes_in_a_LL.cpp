#include <iostream>
#include <cassert>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* divide(int N, Node *head) {
        (void)N;
        Node *evenStart = nullptr, *evenEnd = nullptr;
        Node *oddStart = nullptr, *oddEnd = nullptr;
        Node *cur = head;

        while (cur != nullptr) {
            int val = cur->data;
            if (val % 2 == 0) {
                if (!evenStart) { evenStart = cur; evenEnd = evenStart; }
                else { evenEnd->next = cur; evenEnd = evenEnd->next; }
            } else {
                if (!oddStart) { oddStart = cur; oddEnd = oddStart; }
                else { oddEnd->next = cur; oddEnd = oddEnd->next; }
            }
            cur = cur->next;
        }

        if (!evenStart || !oddStart) return head;

        evenEnd->next = oddStart;
        oddEnd->next = nullptr;
        return evenStart;
    }
};

int main() {
    Node* head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(2);

    Solution sol;
    head = sol.divide(5, head);
    cout << "Segregated even and odd: ";
    Node* cur = head;
    while (cur) { cout << cur->data << " "; cur = cur->next; }
    cout << endl;
    assert(head->data == 8 && head->next->data == 2);

    // Free allocated memory
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    return 0;
}
