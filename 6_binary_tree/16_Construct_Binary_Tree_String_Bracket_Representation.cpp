#include <cassert>
#include <cctype>
#include <iostream>
#include <string_view>
#include <vector>

struct Node {
    int data;
    Node* left;
    Node* right;
    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

class Solution {
private:
    Node* treeFromStringHelper(std::string_view s, size_t &i) {
        if (i >= s.length()) return nullptr;

        int num = 0;
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        }
        while (i < s.length() && std::isdigit(static_cast<unsigned char>(s[i]))) {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        Node* root = new Node(sign * num);

        if (i < s.length() && s[i] == '(') {
            i++; // consume '('
            root->left = treeFromStringHelper(s, i);
            if (i < s.length() && s[i] == ')') {
                i++; // consume ')'
            }
        }
        if (i < s.length() && s[i] == '(') {
            i++; // consume '('
            root->right = treeFromStringHelper(s, i);
            if (i < s.length() && s[i] == ')') {
                i++; // consume ')'
            }
        }
        return root;
    }

public:
    Node* treeFromString(std::string_view s) {
        size_t i = 0;
        return treeFromStringHelper(s, i);
    }
};

void getInorder(const Node* root, std::vector<int> &res) {
    if (!root) return;
    getInorder(root->left, res);
    res.push_back(root->data);
    getInorder(root->right, res);
}

int main() {
    Solution sol;
    std::string_view s = "4(2(3)(1))(6(5))";
    Node* root = sol.treeFromString(s);

    std::vector<int> in;
    getInorder(root, in);
    // Tree:
    // root 4
    // left: 2 (left: 3, right: 1)
    // right: 6 (left: 5)
    // Inorder: 3, 2, 1, 4, 5, 6
    std::vector<int> expected = {3, 2, 1, 4, 5, 6};
    assert(in == expected);

    freeTree(root);

    std::cout << "6_binary_tree 16_Construct_Binary_Tree_String_Bracket_Representation: All tests passed.\n";
    return 0;
}
