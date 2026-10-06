#include <iostream>

using namespace std;

class Solution {
public:
    int setAllRangeBits(int N, int L, int R) {
        int mask = ((1 << R) - 1) ^ ((1 << (L - 1)) - 1);
        return N | mask;
    }
};

int main() {
    Solution sol;
    int n = 17, l = 2, r = 3;
    cout << "Set range [" << l << ", " << r << "] in " << n << ": " << sol.setAllRangeBits(n, l, r) << endl;
    return 0;
}
