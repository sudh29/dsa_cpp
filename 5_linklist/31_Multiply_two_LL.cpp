#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

long long multiplyTwoList(Node* first, Node* second) {
    long long num1 = 0, num2 = 0;
    long long MOD = 1000000007;

    while (first != nullptr) {
        num1 = (num1 * 10 + first->data) % MOD;
        first = first->next;
    }
    while (second != nullptr) {
        num2 = (num2 * 10 + second->data) % MOD;
        second = second->next;
    }
    return (num1 * num2) % MOD;
}

int main() {
    Node* a = new Node(3); a->next = new Node(2); // 32
    Node* b = new Node(2); // 2
    cout << "Product of two lists (32 * 2): " << multiplyTwoList(a, b) << endl;
    return 0;
}
