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
    vector<int> zigZagTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level(sz);
            for (int i = 0; i < sz; i++) {
                Node* cur = q.front();
                q.pop();
                int idx = leftToRight ? i : (sz - 1 - i);
                level[idx] = cur->data;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            leftToRight = !leftToRight;
            for (int v : level) res.push_back(v);
        }
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    Solution sol;
    auto res = sol.zigZagTraversal(root);
    cout << "ZigZag traversal: ";
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
