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

class Solution {
public:
    vector<int> levelOrder(Node* root) {
        vector<int> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            res.push_back(cur->data);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    auto res = sol.levelOrder(root);
    cout << "Level order: ";
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
