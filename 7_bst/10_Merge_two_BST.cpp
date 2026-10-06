#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void inorder(Node* root, vector<int> &res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);
    }

    vector<int> merge(Node *root1, Node *root2) {
        vector<int> a, b;
        inorder(root1, a);
        inorder(root2, b);

        vector<int> res;
        size_t i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) res.push_back(a[i++]);
            else res.push_back(b[j++]);
        }
        while (i < a.size()) res.push_back(a[i++]);
        while (j < b.size()) res.push_back(b[j++]);
        return res;
    }
};

int main() {
    Node* r1 = new Node(3); r1->left = new Node(1); r1->right = new Node(5);
    Node* r2 = new Node(4); r2->left = new Node(2); r2->right = new Node(6);

    Solution sol;
    auto merged = sol.merge(r1, r2);
    cout << "Merged two BSTs elements: ";
    for (int v : merged) cout << v << " ";
    cout << endl;
    return 0;
}
