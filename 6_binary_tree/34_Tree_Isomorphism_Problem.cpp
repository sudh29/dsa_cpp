#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isIsomorphic(Node *root1, Node *root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->data != root2->data) return false;

        bool same = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
        bool swapped = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);
        return same || swapped;
    }
};

int main() {
    Node* r1 = new Node(1); r1->left = new Node(2); r1->right = new Node(3);
    Node* r2 = new Node(1); r2->left = new Node(3); r2->right = new Node(2);

    Solution sol;
    cout << "Trees are isomorphic: " << (sol.isIsomorphic(r1, r2) ? "Yes" : "No") << endl;
    return 0;
}
