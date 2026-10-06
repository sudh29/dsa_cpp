#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> reverseLevelOrder(Node *root) {
    vector<int> res;
    if (!root) return res;
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
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    auto res = reverseLevelOrder(root);
    cout << "Reverse level order: ";
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
