#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int x) : key(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        if (!root) return;

        if (root->key == key) {
            if (root->left) {
                Node* tmp = root->left;
                while (tmp->right) tmp = tmp->right;
                pre = tmp;
            }
            if (root->right) {
                Node* tmp = root->right;
                while (tmp->left) tmp = tmp->left;
                suc = tmp;
            }
            return;
        }

        if (root->key > key) {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        } else {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
    }
};

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);

    Node *pre = nullptr, *suc = nullptr;
    Solution sol;
    sol.findPreSuc(root, pre, suc, 30);
    cout << "For key 30 -> Predecessor: " << (pre ? pre->key : -1) << ", Successor: " << (suc ? suc->key : -1) << endl;
    return 0;
}
