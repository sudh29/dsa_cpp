#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

bool canRepresentBST(int pre[], int n) {
    stack<int> s;
    int root = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (pre[i] < root) return false;
        while (!s.empty() && s.top() < pre[i]) {
            root = s.top();
            s.pop();
        }
        s.push(pre[i]);
    }
    return true;
}

int main() {
    int pre1[] = {40, 30, 35, 80, 100};
    int pre2[] = {40, 30, 35, 20, 80, 100};
    cout << "pre1 is valid BST: " << (canRepresentBST(pre1, 5) ? "Yes" : "No") << endl;
    cout << "pre2 is valid BST: " << (canRepresentBST(pre2, 6) ? "Yes" : "No") << endl;
    return 0;
}
