#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

struct CompareNode {
    bool operator()(Node* a, Node* b) { return a->data > b->data; }
};

class Solution {
public:
    Node *mergeKLists(Node *arr[], int K) {
        priority_queue<Node*, vector<Node*>, CompareNode> pq;
        for (int i = 0; i < K; i++) {
            if (arr[i]) pq.push(arr[i]);
        }

        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (!pq.empty()) {
            Node* top = pq.top();
            pq.pop();
            tail->next = top;
            tail = tail->next;
            if (top->next) pq.push(top->next);
        }
        return dummy->next;
    }
};

int main() {
    Node* l1 = new Node(1); l1->next = new Node(4);
    Node* l2 = new Node(2); l2->next = new Node(5);
    Node* l3 = new Node(3); l3->next = new Node(6);

    Node* arr[] = {l1, l2, l3};
    Solution sol;
    Node* merged = sol.mergeKLists(arr, 3);
    cout << "Merged K sorted LL: ";
    while (merged) { cout << merged->data << " "; merged = merged->next; }
    cout << endl;
    return 0;
}
