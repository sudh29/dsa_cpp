#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        (void)n;
        unordered_map<int, stack<int>> mp;
        for (int i = 0; i < 2 * e; i += 2) {
            mp[A[i]].push(A[i + 1]);
        }
        for (int i = 0; i < 2 * e; i += 2) {
            if (mp[B[i]].empty() || mp[B[i]].top() != B[i + 1]) return 0;
            mp[B[i]].pop();
        }
        return 1;
    }
};

int main() {
    int A[] = {1, 2, 1, 3};
    int B[] = {1, 3, 1, 2};
    Solution sol;
    int res = sol.checkMirrorTree(3, 2, A, B);
    cout << "Are N-ary trees mirrors: " << (res ? "Yes" : "No") << endl;
    assert(res == 1);
    return 0;
}
