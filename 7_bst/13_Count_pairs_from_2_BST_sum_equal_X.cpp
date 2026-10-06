#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void insertSet(Node* root, unordered_set<int> &s) {
        if (!root) return;
        insertSet(root->left, s);
        s.insert(root->data);
        insertSet(root->right, s);
    }

    void countPairsUtil(Node* root, const unordered_set<int> &s, int x, int &count) {
        if (!root) return;
        countPairsUtil(root->left, s, x, count);
        if (s.find(x - root->data) != s.end()) count++;
        countPairsUtil(root->right, s, x, count);
    }

    int countPairs(Node* root1, Node* root2, int x) {
        unordered_set<int> s;
        insertSet(root1, s);
        int count = 0;
        countPairsUtil(root2, s, x, count);
        return count;
    }
};

int main() {
    Node* r1 = new Node(5); r1->left = new Node(3); r1->right = new Node(7);
    Node* r2 = new Node(10); r2->left = new Node(6); r2->right = new Node(15);

    Solution sol;
    cout << "Pairs summing to 16: " << sol.countPairs(r1, r2, 16) << endl;
    return 0;
}
