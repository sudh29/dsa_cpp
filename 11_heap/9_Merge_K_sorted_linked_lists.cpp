#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

struct Node {
    int data;
    Node* next;
    explicit Node(int x) : data(x), next(nullptr) {}
};

void freeList(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

struct CompareNode {
    bool operator()(const Node* a, const Node* b) const {
        return a->data > b->data;
    }
};

class Solution {
public:
    Node* mergeKLists(const std::vector<Node*> &arr) {
        std::priority_queue<Node*, std::vector<Node*>, CompareNode> pq;
        for (Node* node : arr) {
            if (node) pq.push(node);
        }

        Node dummy(0);
        Node* tail = &dummy;

        while (!pq.empty()) {
            Node* top = pq.top();
            pq.pop();
            tail->next = top;
            tail = tail->next;
            if (top->next) {
                pq.push(top->next);
            }
        }
        return dummy.next;
    }
};

int main() {
    Node* l1 = new Node(1); l1->next = new Node(4);
    Node* l2 = new Node(2); l2->next = new Node(5);
    Node* l3 = new Node(3); l3->next = new Node(6);

    std::vector<Node*> arr = {l1, l2, l3};
    Solution sol;
    Node* merged = sol.mergeKLists(arr);

    std::vector<int> vals;
    for (Node* curr = merged; curr != nullptr; curr = curr->next) {
        vals.push_back(curr->data);
    }
    std::vector<int> expected = {1, 2, 3, 4, 5, 6};
    assert(vals == expected);

    freeList(merged);

    // Test with empty lists
    std::vector<Node*> emptyArr = {nullptr, nullptr};
    Node* emptyMerged = sol.mergeKLists(emptyArr);
    assert(emptyMerged == nullptr);

    std::cout << "11_heap 9_Merge_K_sorted_linked_lists: All tests passed.\n";
    return 0;
}
