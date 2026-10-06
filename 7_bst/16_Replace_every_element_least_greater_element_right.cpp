#include <cassert>
#include <iostream>
#include <span>
#include <vector>

struct Node {
    int data;
    Node *left;
    Node *right;
    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

Node* insert(Node* node, int data, Node*& succ) {
    if (!node) return new Node(data);
    if (data < node->data) {
        succ = node;
        node->left = insert(node->left, data, succ);
    } else {
        node->right = insert(node->right, data, succ);
    }
    return node;
}

std::vector<int> findLeastGreater(std::span<const int> arr) {
    size_t n = arr.size();
    std::vector<int> res(n, -1);
    Node* root = nullptr;

    for (size_t i = n; i > 0; --i) {
        size_t idx = i - 1;
        Node* succ = nullptr;
        root = insert(root, arr[idx], succ);
        if (succ) {
            res[idx] = succ->data;
        }
    }

    freeTree(root);
    return res;
}

int main() {
    std::vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    auto res = findLeastGreater(arr);

    assert(res[0] == 18); // Least greater on right of 8 is 18
    assert(res.back() == -1); // Last element has nothing on right

    std::vector<int> simple = {5, 4, 3, 2, 1};
    auto resSimple = findLeastGreater(simple);
    std::vector<int> expectedSimple = {-1, -1, -1, -1, -1};
    assert(resSimple == expectedSimple);

    std::cout << "7_bst 16_Replace_every_element_least_greater_element_right: All tests passed.\n";
    return 0;
}
