#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* removeDuplicates(Node* head) {
        if (!head) return nullptr;
        unordered_set<int> seen;
        Node* cur = head;
        Node* prev = nullptr;

        while (cur != nullptr) {
            if (seen.find(cur->data) != seen.end()) {
                prev->next = cur->next;
                delete cur;
            } else {
                seen.insert(cur->data);
                prev = cur;
            }
            cur = prev->next;
        }
        return head;
    }
};

int main() {
    Node* head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    Solution sol;
    head = sol.removeDuplicates(head);
    cout << "Deduplicated unsorted list: ";
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
    return 0;
}
