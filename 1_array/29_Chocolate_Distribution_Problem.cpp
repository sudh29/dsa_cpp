#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long findMinDiff(vector<long long> a, long long n, long long m) {
        if (m == 0 || n == 0 || m > n) return 0;
        sort(a.begin(), a.end());
        long long min_diff = LLONG_MAX;

        for (int i = 0; i + m - 1 < n; i++) {
            long long diff = a[i + m - 1] - a[i];
            min_diff = min(min_diff, diff);
        }
        return min_diff;
    }
};

int main() {
    Solution sol;
    vector<long long> a = {3, 4, 1, 9, 56, 7, 9, 12};
    long long m = 5;
    cout << "Min chocolate difference for " << m << " children: " << sol.findMinDiff(a, a.size(), m) << endl;
    return 0;
}
