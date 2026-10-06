#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long int findMaxProduct(vector<int>& a, int n) {
        if (n == 1) return a[0];
        long long int MOD = 1e9 + 7;
        int zeroCount = 0, negCount = 0;
        int maxNeg = INT_MIN;
        long long int prod = 1;

        for (int v : a) {
            if (v == 0) { zeroCount++; continue; }
            if (v < 0) {
                negCount++;
                maxNeg = max(maxNeg, v);
            }
            prod = (prod * v) % MOD;
        }

        if (zeroCount == n) return 0;
        if (negCount % 2 != 0) {
            if (negCount == 1 && zeroCount + negCount == n) return 0;
            prod /= maxNeg;
        }
        return (prod % MOD + MOD) % MOD;
    }
};

int main() {
    Solution sol;
    vector<int> a = {-1, -1, -2, 4, 3};
    cout << "Max product subset: " << sol.findMaxProduct(a, a.size()) << endl;
    return 0;
}
