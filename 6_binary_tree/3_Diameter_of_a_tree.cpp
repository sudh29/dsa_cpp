#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int heightAndDiameter(Node* root, int &dia) {
        if (!root) return 0;
        int lh = heightAndDiameter(root->left, dia);
        int rh = heightAndDiameter(root->right, dia);
        dia = max(dia, 1 + lh + rh);
        return 1 + max(lh, rh);
    }

    int diameter(Node* root) {
        int dia = 0;
        heightAndDiameter(root, dia);
        return dia;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    cout << "Diameter of tree: " << sol.diameter(root) << endl;
    return 0;
}
