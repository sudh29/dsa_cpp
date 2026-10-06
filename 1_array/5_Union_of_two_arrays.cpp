#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int doUnion(int a[], int n, int b[], int m) {
        unordered_set<int> s;
        for (int i = 0; i < n; i++) s.insert(a[i]);
        for (int i = 0; i < m; i++) s.insert(b[i]);
        return s.size();
    }
};

int main() {
    Solution sol;
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3};
    cout << "Union size: " << sol.doUnion(a, 5, b, 3) << endl;
    return 0;
}
