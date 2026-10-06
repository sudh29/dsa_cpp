#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> bottomView(Node *root) {
    vector<int> res;
    if (!root) return res;
    map<int, int> botNode;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [cur, hd] = q.front();
        q.pop();
        botNode[hd] = cur->data;
        if (cur->left) q.push({cur->left, hd - 1});
        if (cur->right) q.push({cur->right, hd + 1});
    }

    for (const auto &[hd, val] : botNode) res.push_back(val);
    return res;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(25);

    auto res = bottomView(root);
    cout << "Bottom view: ";
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
