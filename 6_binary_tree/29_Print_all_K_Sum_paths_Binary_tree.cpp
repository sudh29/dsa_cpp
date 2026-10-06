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
    void printKPathUtil(Node *root, vector<int>& path, int k, int &count) {
        if (!root) return;
        path.push_back(root->data);
        printKPathUtil(root->left, path, k, count);
        printKPathUtil(root->right, path, k, count);

        int sum = 0;
        for (int j = path.size() - 1; j >= 0; j--) {
            sum += path[j];
            if (sum == k) count++;
        }
        path.pop_back();
    }

    int sumK(Node *root, int k) {
        vector<int> path;
        int count = 0;
        printKPathUtil(root, path, k, count);
        return count;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);

    Solution sol;
    cout << "Paths with sum 5: " << sol.sumK(root, 5) << endl;
    return 0;
}
