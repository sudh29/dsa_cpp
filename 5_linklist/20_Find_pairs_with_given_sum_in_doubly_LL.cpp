#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> res;
        if (!head) return res;

        Node *first = head;
        Node *second = head;
        while (second->next != nullptr) second = second->next;

        while (first != second && second->next != first) {
            int sum = first->data + second->data;
            if (sum == target) {
                res.push_back({first->data, second->data});
                first = first->next;
                second = second->prev;
            } else if (sum < target) {
                first = first->next;
            } else {
                second = second->prev;
            }
        }
        return res;
    }
};

int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(4);
    Node* n4 = new Node(5);
    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;

    Solution sol;
    auto pairs = sol.findPairsWithGivenSum(head, 6);
    cout << "Pairs with sum 6 in DLL: ";
    for (const auto &p : pairs) cout << "(" << p.first << ", " << p.second << ") ";
    cout << endl;
    return 0;
}
