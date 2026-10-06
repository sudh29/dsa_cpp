#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int countSquares(int N) {
        if (N <= 1) return 0;
        int sq = (int)sqrt(N - 1);
        return sq;
    }
};

int main() {
    Solution sol;
    int n = 9;
    cout << "Count of perfect squares less than " << n << ": " << sol.countSquares(n) << endl;
    return 0;
}
