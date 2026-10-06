#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void reverseLevelOrderPrint(Node* root) {
    if (!root) return;
    queue<Node*> q;
    stack<int> s;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        s.push(cur->data);
        if (cur->right) q.push(cur->right);
        if (cur->left) q.push(cur->left);
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout << "Reverse level order print: ";
    reverseLevelOrderPrint(root);
    return 0;
}
