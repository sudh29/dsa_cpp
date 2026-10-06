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

class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> res;
        if (!root) return res;
        map<int, int> topNode; // hd -> val
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto [cur, hd] = q.front();
            q.pop();
            if (topNode.find(hd) == topNode.end()) {
                topNode[hd] = cur->data;
            }
            if (cur->left) q.push({cur->left, hd - 1});
            if (cur->right) q.push({cur->right, hd + 1});
        }

        for (const auto &[hd, val] : topNode) {
            res.push_back(val);
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
    auto res = sol.topView(root);
    cout << "Top view: ";
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
