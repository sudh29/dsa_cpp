#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

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

vector<int> findLeastGreater(int arr[], int n) {
    vector<int> res(n, -1);
    Node* root = nullptr;
    for (int i = n - 1; i >= 0; i--) {
        Node* succ = nullptr;
        root = insert(root, arr[i], succ);
        if (succ) res[i] = succ->data;
    }
    return res;
}

int main() {
    int arr[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    auto res = findLeastGreater(arr, n);
    cout << "Least greater on right for 8: " << res[0] << endl;
    return 0;
}
