#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Node* treeFromStringHelper(const string &s, int &i) {
        if (i >= (int)s.length()) return nullptr;

        int num = 0, sign = 1;
        if (s[i] == '-') { sign = -1; i++; }
        while (i < (int)s.length() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        Node* root = new Node(sign * num);

        if (i < (int)s.length() && s[i] == '(') {
            i++; // consume '('
            root->left = treeFromStringHelper(s, i);
            i++; // consume ')'
        }
        if (i < (int)s.length() && s[i] == '(') {
            i++; // consume '('
            root->right = treeFromStringHelper(s, i);
            i++; // consume ')'
        }
        return root;
    }

    Node *treeFromString(string s) {
        int i = 0;
        return treeFromStringHelper(s, i);
    }
};

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Solution sol;
    string s = "4(2(3)(1))(6(5))";
    Node* root = sol.treeFromString(s);
    cout << "Inorder of bracket constructed tree: ";
    inorder(root);
    cout << endl;
    return 0;
}
