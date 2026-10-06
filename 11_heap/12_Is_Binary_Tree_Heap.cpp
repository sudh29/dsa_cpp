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
    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isComplete(Node* root, int index, int totalNodes) {
        if (!root) return true;
        if (index >= totalNodes) return false;
        return isComplete(root->left, 2 * index + 1, totalNodes) &&
               isComplete(root->right, 2 * index + 2, totalNodes);
    }

    bool isHeapProperty(Node* root) {
        if (!root->left && !root->right) return true;
        if (!root->right) {
            return root->data >= root->left->data;
        }
        if (root->data >= root->left->data && root->data >= root->right->data) {
            return isHeapProperty(root->left) && isHeapProperty(root->right);
        }
        return false;
    }

    bool isHeap(Node* root) {
        if (!root) return true;
        int total = countNodes(root);
        return isComplete(root, 0, total) && isHeapProperty(root);
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);

    Solution sol;
    cout << "Is tree a valid max-heap: " << (sol.isHeap(root) ? "Yes" : "No") << endl;
    return 0;
}
