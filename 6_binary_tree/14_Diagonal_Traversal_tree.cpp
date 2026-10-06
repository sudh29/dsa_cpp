#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> diagonal(Node *root) {
    vector<int> res;
    if (!root) return res;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        while (cur) {
            res.push_back(cur->data);
            if (cur->left) q.push(cur->left);
            cur = cur->right;
        }
    }
    return res;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);

    auto res = diagonal(root);
    cout << "Diagonal traversal: ";
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
