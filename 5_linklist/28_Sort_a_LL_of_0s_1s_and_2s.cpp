#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* segregate(Node *head) {
        int count[3] = {0, 0, 0};
        Node *ptr = head;
        while (ptr != nullptr) {
            count[ptr->data]++;
            ptr = ptr->next;
        }

        int i = 0;
        ptr = head;
        while (ptr != nullptr) {
            if (count[i] == 0) {
                i++;
            } else {
                ptr->data = i;
                count[i]--;
                ptr = ptr->next;
            }
        }
        return head;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(0);

    Solution sol;
    head = sol.segregate(head);
    cout << "Segregated 0s, 1s, 2s LL: ";
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
    return 0;
}
